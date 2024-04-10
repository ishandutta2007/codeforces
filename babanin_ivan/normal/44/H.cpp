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

ll d[55][15];

bool check(string s){
    int n=s.size();
    for (int i=0;i<n-1;i++){
        int tmp=s[i]-'0'+s[i+1]-'0';
        int a=tmp/2;
        int b=tmp/2+tmp%2;
        if (s[i+1]-'0'==a || s[i+1]-'0'==b) continue;
        return false;       
    }
    return true;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    string s;
    getline(cin, s);    
    int n;
    n = s.size();
    forn(i, 10)
        d[0][i] = 1;
    for (int i = 0; i < n-1; i ++){
        forn(j, 10){
            int tmp=j+s[i+1]-'0';
            int a=tmp/2;
            int b=tmp/2+tmp%2;
            d[i+1][a]+=d[i][j];
            if (a!=b)
                d[i+1][b]+=d[i][j];
        }
//      for (int j=0;j<10;j++)
//          cerr<<d[i+1][j]<<" \n"[j==9];
    }
    ll ans = 0;
    forn(i, 10)
        ans += d[n - 1][i]; 
    ans-=check(s);
    cout << ans;
  return 0;
}