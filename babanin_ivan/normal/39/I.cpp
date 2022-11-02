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

int ans;

int gcd(int a,int b){
    if (!a || !b) return a+b;
    return gcd(b,a%b);
}

const int maxn=110000;

vector<int> g[maxn];
vector<int> gt[maxn];
int d[maxn];
int n;

const int inf=1<<29;

void bfs(){
    for (int i=0;i<n;i++)
        d[i]=inf;
    d[0]=0;
    queue<int> q;
    q.push(0);
    for (;!q.empty();){
        int v=q.front();
        q.pop();
        int sz=g[v].size();
        for (int i=0;i<sz;i++)
            if (d[v]+1<d[g[v][i]]){
                d[g[v][i]]=d[v]+1;
                q.push(g[v][i]);
            }
    }
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        g[a].pb(b);
        gt[b].pb(a);
//      cerr<<b<<" "<<a<<" "<<gt[0].size()<<endl;
    }
    bfs();
    int ans=0;
    for (int i=0;i<n;i++)
        if (d[i]!=inf){
            int tmp=0;
            for (int j=0;j<gt[i].size();j++)
                if (d[gt[i][j]]!=inf)
                    tmp=gcd(tmp,d[gt[i][j]]+1-d[i]);
//          cerr<<i<<" "<<tmp<<endl;
            ans=gcd(ans,tmp);
        }
    cout<<ans<<endl;
    int kol=0;
    for (int i=0;i<n;i++)
        if (d[i]!=inf && d[i]%ans==0)
            kol++;
    cout<<kol<<endl;
    for (int i=0;i<n;i++)
        if (d[i]!=inf && d[i]%ans==0)
            printf("%d ",i+1);
    printf("\n");
    return 0;
}