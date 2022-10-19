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
	int m;cin >> m;
	for(int i=0;i<m;i++)
	{
		int n;
		cin >> n;
		
		bool ans=false;
		for(int i=360;i>=3;i--)
		{
			if((i-2)*180/i==n && (i-2)*180%i==0)
			{
				ans=true;
				break;
			}
		}
		
		if(ans)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}