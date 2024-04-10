#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 20000000000000
#define N 200000



int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
	int n,k;
	cin >> n >> k;
	vector<int> work(n),boost(n);
	for(int i = 0;i < n;i++)
		cin >> work[i];
	int a;
	cin >> a;
	for(int i = 0;i < n;i++)
		cin >> boost[i];

	multiset<int> s;
	bool ch = 1;
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		s.insert(boost[i]);
		while(k < work[i] and !s.empty())
		{
			ans += *s.begin();
			s.erase(s.begin());
			k += a;
			// cerr << i << " " << k << endl;
		}

		if(k < work[i])
			ch = 0;
	}
	if(ch == 0)
		cout << -1;
	else
		cout << ans;

    
}