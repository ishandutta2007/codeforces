#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

string w[] = {"HL" , "T"};

int a[maxn];

void solve()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	set<pair<int , int> > st;
	for(int i = 0; i < n; i++)
		st.insert({a[i] , i});

	int last = -1 , s = 0;

	while(!st.empty())
	{
		auto it = st.end();
		it--;

		if((it -> second) == last)
		{
			if(it == st.begin())
			{
				cout << w[s] << endl;
				return;
			}
			it--;
		}

		last = (it -> second);
		st.erase(it);
		a[last]--;

		if(a[last])
			st.insert({a[last] , last});

		s = 1 - s;
	}

	cout << w[s] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();

}