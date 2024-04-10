#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

string a, b;
int n, m, k, ans1=0, ans2=0;
set<pair<char, char> > s;

bool check(char ch1, char ch2)
{
	return s.find({ch1, ch2})!=s.end();
}

int32_t main()
{
	IOS;
	s.insert({'S', 'R'});
	s.insert({'P', 'S'});	
	s.insert({'R', 'P'});
	cin>>n>>a>>b;
	m=a.size();
	k=b.size();
	int period=m*k/__gcd(m, k);
	for(int i=0;i<period && i<n;i++)
	{
		int occur=1 + (n-i-1)/period;
		ans1+=check(a[i%m], b[i%k]) * occur;
		ans2+=check(b[i%k], a[i%m]) * occur;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}