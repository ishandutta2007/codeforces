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

int a[200];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        --l,--r;
        for (int j=l;j<=r;j++)
            a[j]++;
    }
    for (int i=0;i<n;i++)
        if (a[i]!=1){
            printf("%d %d",i+1,a[i]);
            return 0;   
        }
    cout<<"OK"<<endl;
    return 0;
}