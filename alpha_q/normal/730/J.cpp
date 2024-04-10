/*
ID: Asif Jawad
LANG: C++
TASK:
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <iterator>
#include <utility>
#include <sstream>

using namespace std;

#define Read(f) freopen(f,"r",stdin)
#define Write(f) freopen(f,"w",stdout)

#define sf(n) scanf("%d",&n)
#define sff(n) scanf("%lld",&n)
#define sfs(s) scanf("%s",s)
#define pf printf

#define pi acos(-1)
#define eps 1e-9
#define mem(a,n) memset(a,n,sizeof a)
#define countbit(x) __builtin_popcountll(x)

#define rep(i,n) for(int i = 0;i < n;i++)
#define Rep(i,a,n) for(int i = (a) ;i < n;i++)
#define REP(i,a,n) for(int i = (a); i >= n;i--)

#define pb push_back
#define sz size()
#define mp make_pair
#define all(c) (c).begin(),(c).end()
//#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ( (c).find(x) != (c).end() )
#define cpresent(c,x) ( find(all(c),x) != (c).end() )
#define ff first
#define ss second
#define fl fflush(stdout)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector< vi >vvi;

inline int Set(int N,int pos)
{
    return N = N | (1 << pos);
}
inline int Reset(int N,int pos)
{
    return N = N & ~ (1 <<pos);
}
inline bool check(int N,int pos)
{
    return (bool) (N & (1 << pos) );
}

template<class T>
T gcd(T a,T b)
{
    return (!b) ? a : gcd( b, a%b );
}

template <class T>
T lcm(T a,T b)
{
    return (a / gcd(a,b)) * b;
}


//template ends here

int a[105],b[105];
pii dp[105][105*105];
int n,s;

pii call(int i,int w)
{
    if(i == n){

        if(w >= s)return mp(0,0);
        return mp(123456789,123456789);
    }
    if(dp[i][w].ff != -1)return dp[i][w];

    pii ret1 = call(i+1,w+b[i]),ret2=call(i+1,w);

    if(1+ret1.ff == ret2.ff)return dp[i][w] = mp(1+ret1.ff,max(ret1.ss+a[i],ret2.ss));

    return dp[i][w] = min( mp(1+ret1.ff,ret1.ss+a[i]),ret2 );
}

int main()
{

    //Read("in");
    //Write(".out");

    //ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	rep(i,n){

		cin >> a[i];
		s += a[i];
	}
	rep(i,n){

		cin >> b[i];
	}
	mem(dp,-1);

	cout << call(0,0).ff << ' ' << s-call(0,0).ss << endl;

    return 0;
}