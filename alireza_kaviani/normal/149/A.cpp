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
	vi a(12);
	int k , s=0; cin >> k;
	for(int i=0;i<12;i++)
	{
		cin >> a[i];
		s+=a[i];
	}
	if(s<k)
	{
		cout << -1 << endl;
		return 0;
	}
	
	Sort(a);
	
	int sum=0  , ans=0;
	while(sum<k)
	{
		ans++;
		sum+=a[12-ans];
	}
	cout << ans << endl;
}