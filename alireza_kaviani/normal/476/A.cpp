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

int main()
{
	int n , m;
	cin >> n >> m;
	
	if(m>n)
	{
		cout << -1 << endl;
		return 0;
	}
	
	int t=n/2 + n%2;
	if(t%m==0)
	{
		cout << t << endl;
		return 0;
	}
	
	cout << t+(m-t%m) << endl;
	return 0;
}