#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		if(sum % n)
			cout << -1 << endl;
		else
		{
			int reqd = sum / n;
			vector<int> p, q, r;
			for(int i = 2; i <= n; i++)
			{
				int rem = a[i] % i;
				if(rem)
				{
					int val = i - rem;
					p.push_back(1);
					q.push_back(i);
					r.push_back(val);
					a[1] -= val;
					a[i] += val;
				}
				int take = a[i] / i;
				a[1] += take * i;
				a[i] = 0;
				p.push_back(i);
				q.push_back(1);
				r.push_back(take);
			}
			for(int i = 2; i <= n; i++)
			{
				p.push_back(1);
				q.push_back(i);
				r.push_back(reqd);
			}
			cout << p.size() << endl;
			for(int i = 0; i < p.size(); i++)
				cout << p[i] << " " << q[i] << " " << r[i] << endl;
		}
	}
	return 0;
}