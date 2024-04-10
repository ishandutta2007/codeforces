#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<ld> vld;

#define all(x)       (x).begin(),(x).end()
#define Sort(x)      sort(all((x)))
#define pb           push_back
#define ppb          pop_back
#define pf           push_front
#define ppf          pop_front
#define X            first
#define Y            second

int main()
{
	vector<ll> dp(100010) , cnt(100010,0);
	ll n;
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		cnt[t]++;
	}
	
	dp[0]=0;
	for(int i=1;i<100010;i++)
	{
		dp[i]=max(dp[i-1],dp[(i>=2)?i-2:0]+i*cnt[i]);
	}
	
	cout << dp[100009];
}