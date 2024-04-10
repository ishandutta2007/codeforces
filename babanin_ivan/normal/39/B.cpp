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
#define forn(i, n) for(int i = 0; i < n; i ++)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

vector <int> ans;
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n, schet = 1, t;
    cin >> n;
    forn(i, n){
        scanf ("%d", &t);
        if (t == schet){
            ans.pb(i + 2001);
            schet ++;
        }
    }
    cout << ans.size() << endl;
    forn(i, ans.size())
        printf ("%d ", ans[i]);
  return 0;
}