#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long tmp;
	cin >> n;
	vector <pair <long long, int>> a;
	fop (i,0,n) {
		cin >> tmp;
		int now = 1;
		while (a.size() and a.back().X * now >= tmp * a.back().Y) {
			now += a.back().Y;
			tmp += a.back().X;
			a.pop_back();
		}
		a.push_back({tmp, now});
	}
	cout << fixed << setprecision(11);
	for (auto i : a) {
		double aaa = 1.0 * i.X / i.Y;
		while (i.Y--) {
			cout << aaa << '\n';
		}
	}
}