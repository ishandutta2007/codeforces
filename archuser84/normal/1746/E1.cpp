#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	while (a.size() > 3) {
		int b0 = a.size()/4 + (a.size()%4 > 0);
		int b1 = a.size()/4 + (a.size()%4 > 1) + b0;
		int b2 = a.size()/4 + (a.size()%4 > 2) + b1;
		vector<int> x1, x2;
		Loop (i,0,b0) {
			x1.push_back(a[i]);
			x2.push_back(a[i]);
		}
		Loop (i,b0,b1) {
			x1.push_back(a[i]);
		}
		Loop (i,b1,b2) {
			x2.push_back(a[i]);
		}
		cout << "? ";
		cout << x1.size() << ' ';
		for (int x : x1)
			cout << x << ' ' ;
		cout << endl;
		string s;
		int ans1, ans2;
		cin >> s;
		ans1 = s[0] == 'Y';
		cout << "? ";
		cout << x2.size() << ' ';
		for (int x : x2)
			cout << x << ' ' ;
		cout << endl;
		cin >> s;
		ans2 = s[0] == 'Y';
		vector<int> new_a;
		if (ans1 || ans2)
			Loop (i,0,b0)
				new_a.push_back(a[i]);
		if (ans1 || !ans2)
			Loop (i,b0,b1)
				new_a.push_back(a[i]);
		if (!ans1 || ans2)
			Loop (i,b1,b2)
				new_a.push_back(a[i]);
		if (!ans1 || !ans2)
			Loop (i,b2,a.size())
				new_a.push_back(a[i]);
		a = new_a;
	}
	string s;
	cout << "? 1 " << a[0] << endl;
	cin >> s;
	bool ans = s[0] == 'Y';
	if (!ans) {
		cout << "? 1 " << a[0] << endl;
		cin >> s;
		ans = s[0] == 'Y';
	}
	if (!ans) {
		cout << "! " << a[1] << endl;
		cin >> s;
		if (s[1] == ')')
			return 0;
		cout << "! " << a[2] << endl;
		cin >> s;
		if (s[1] == ')')
			return 0;
		assert(false);
	}
	cout << "! " << a[0] << endl;
	cin >> s;
	if (s[1] == ')')
		return 0;
	cout << "? 1 " << a[1] << endl;
	cin >> s;
	cout << "! " << a[1 + (s[0] == 'N')] << endl;
	cin >> s;
	if (s[1] == ')')
		return 0;
	assert(false);
}