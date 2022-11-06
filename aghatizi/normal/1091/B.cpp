#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

int x[maxn] , y[maxn] , a[maxn] , b[maxn];

set<pair<int , int> > st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i] , st.insert(make_pair(a[i] , b[i]));

	for(int match0 = 0; match0 < n; match0++)
	{
		int resx = x[0] + a[match0] , resy = y[0] + b[match0];

		bool is = 1;
		for(int i = 1; i < n; i++)
			is &= st.count(make_pair(resx - x[i] , resy - y[i]));

		if(is)
			return cout << resx << " " << resy << endl , 0;
	}
}