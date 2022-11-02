#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

char a[1100][1100];

int b[1100][1100];
int c[1100][1100];
int n,m;

void error(){
    printf("NO\n");
    exit(0);
}

void color(){
    memset(c,-1,sizeof(c));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            if (b[i][j]==0) continue;           
            if (c[i][j]!=-1) continue;
            bool used[4];
            used[0]=used[1]=used[2]=used[3]=0;
            if (c[i-1][j]!=-1)
                used[c[i-1][j]]=true;
                
            if (c[i][j-1]!=-1)
                used[c[i][j-1]]=true;
                
            if (b[i][j]==b[i][j+1] && c[i-1][j+1]!=-1)
                used[c[i-1][j+1]]=true;
                
            if (b[i][j]==b[i][j+1] && c[i-1][j+2]!=-1)
                used[c[i-1][j+2]]=true;
                            
            if (b[i][j]==b[i][j+1] && c[i][j+3]!=-1)
                used[c[i][j+3]]=true;
            
            if (b[i][j]==b[i+1][j] && c[i][j+1]!=-1)
                used[c[i][j+1]]=true;
                
            if (b[i][j]==b[i+1][j] && c[i+1][j+1]!=-1)
                used[c[i+1][j+1]]=true;
                            
            if (b[i][j]==b[i+1][j] && c[i+1][j-1]!=-1)
                used[c[i+1][j-1]]=true;
                
            if (b[i][j]==b[i+1][j] && c[i+2][j-1]!=-1)
                used[c[i+2][j-1]]=true;

                
            int col=0;
            for (;col<4 && used[col];++col);
            assert(col!=4);
            if (b[i][j]==b[i][j+1])
                c[i][j]=c[i][j+1]=c[i][j+2]=col;
            else
                c[i][j]=c[i+1][j]=c[i+2][j]=col;
        }
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    n+=2;
    m+=2;
    for (int i=1;i<n-1;i++)
        for (int j=1;j<m-1;j++)
            scanf(" %c ",&a[i][j]);
    for (int i=0;i<n;i++)
        a[i][0]=a[i][m-1]='.';
    for (int i=0;i<m;i++)
        a[0][i]=a[n-1][i]='.';
        
        
    int cnt=1;
    for (int i=1;i<n-1;i++)
        for (int j=1;j<m-1;j++)
            if (a[i][j]=='b'){
                if (a[i-1][j]=='w'){
                    if (a[i+1][j]!='w') error();
                    a[i-1][j]=a[i][j]=a[i+1][j]='.';
                    b[i-1][j]=b[i][j]=b[i+1][j]=cnt++;
                    continue;
                }
                if (a[i][j-1]!='w' || a[i][j+1]!='w')
                    error();
                a[i][j-1]=a[i][j]=a[i][j+1]='.';
                b[i][j-1]=b[i][j]=b[i][j+1]=cnt++;
            }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (a[i][j]!='.')
                error();
    color();
    printf("YES\n");
    for (int i=1;i<n-1;i++){
        for (int j=1;j<m-1;j++)
            printf("%c",  char((c[i][j]==-1) ?('.'):(char(c[i][j]+'a'))) );
        printf("\n");
    }       
    return 0;
}