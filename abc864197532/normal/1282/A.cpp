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

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if (a > b) swap(a,b);
		int aa = c - d, bb = c + d;
		if (aa > b and bb > b) {
			cout << b - a << endl;
			continue;
		} else if (aa < a and bb < a) {
			cout << b - a << endl;
			continue;
		}
		if (aa < a) aa = a;
		if (bb > b) bb = b;
		cout << b - a - bb + aa  << endl;
	}
}