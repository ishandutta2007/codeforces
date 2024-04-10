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

int a[1100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    vector<int> ans;
    for (int i=n-1;i>=0;i--)
        if (a[i]>0)
            ans.pb(a[i]);
    for (int i=0;i<n-1;i+=2){
        if (a[i]<0 && a[i+1]<0){
            ans.pb(a[i]);
            ans.pb(a[i+1]);
        }       
    }
    
    if (ans.size()==0)
        ans.pb(a[n-1]);
    for (int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    printf("\n");
    
    return 0;
}