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
	int n , a[3];
	cin >> n;
	for(int i=0;i<3;i++)cin >> a[i];
	
	vector<int> dp(n+1,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[j]<=i)
			{
				int t =dp[i-a[j]]+1;
				if(t!=1 || i==a[j])
				{
					dp[i]=max(dp[i],t);
				}
			}
		}
	}
	
	cout << dp[n] << endl;
}