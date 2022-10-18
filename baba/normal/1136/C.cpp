#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
                    
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
                    
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define pll pair<ll,ll>
#define sz(a) ll((a).size())
#define pb push_back
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)    //checks if ith bit is on
#define set0(x,i) (x & ~(1 << i)) 
 
#define MOD 1000000007
#define INF 10000000000000000
#define MAX 100000+5
// a^b mod m
ll pow(ll a, ll b, ll m)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}
    
    
using namespace std;
    
int main(){
  ll n,m,x,y;
  cin >> n >> m ;
  vector<vector<ll> > matrix1(n), matrix2(n);
  rep(i,0,n)
  {
      rep(j,0,m)
      {
          cin >> x;
          matrix1[i].pb(x);
      }
  } 
  rep(i,0,n)
  {
      rep(j,0,m)
      {
          cin >> x;
          matrix2[i].pb(x);
      }
  } 

  multiset<ll> set1;
  multiset<ll> set2;
  rep(i,0,n+m-1)
  {
      set1.clear();
      set2.clear();
      rep(x,0,n)
      {
          y = i - x ;
          if (y < 0 || y > m-1)
            continue;
          set1.insert(matrix1[x][y]);
          set2.insert(matrix2[x][y]);
      }
      if ( set1 != set2 )
        {
            cout << "NO" << endl;
            
        return 0 ;
        }
  }
  cout << "YES" << endl;
return 0;
}