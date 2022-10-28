#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int l1, r1, l2, r2, k;
vector<int> v;
 
void rec(int x)
{
	if(x <= 1e9)
		v.push_back(x);
	if(x > 1e9)
		return;
	rec(x * 10 + 4);
	rec(x * 10 + 7);
}
 
int32_t main()
{
	IOS;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	rec(0);
	v.push_back(2e9);
	sort(v.begin(), v.end());
	int n = v.size();
	double num = 0;
	double den = (r2 - l2 + 1) * (r1 - l1 + 1);
	for(int i = 0; i + k + 1 < n; i++)
	{
		int j = i + k;
		int range1 = min(v[i + 1], r1) - max(v[i] + 1, l1) + 1;
		int range2 = min(v[j + 1] - 1, r2) - max(v[j], l2) + 1;
		if(range1 >= 0 && range2 >= 0)
			num += range1 * range2;
	}
	for(int i = k; i < n; i++)
	{
		int j = i - k;
		int range1 = min(v[i + 1] - 1, r1) - max(v[i], l1) + 1;
		int range2 = min(v[j + 1], r2) - max(v[j] + 1, l2) + 1;
		if(range1 >= 0 && range2 >= 0)
			num += range1 * range2;
	}
	if(k == 1)
	{
		for(auto &it:v)
		{
			if(it >= l1 && it <= r1 && it >= l2 && it <= r2)
				num--;
		}
	}
	double ans = num / den;
	cout << fixed << setprecision(12) << ans;
	return 0;
}