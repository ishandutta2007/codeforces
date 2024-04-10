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
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
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
 int n,x,y;
 cin >> n;
 vector<ii> book;
 rep(i,0,n) {
     cin >> x >> y ;
     book.pb({i+1,y});
 } 
 int k,ans = n;
 cin >> k;
 for(auto it  = book.begin(); it != book.end(); it++)
 {
     
     if (it->second >= k)
        {cout << ans << endl;
        break;}
        ans -- ;
    
 }
return 0;
}