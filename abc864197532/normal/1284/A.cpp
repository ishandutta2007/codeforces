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

int main() {
	int n,m,tmp,tt;
	cin >> n >> m;
	string s[n], t[m];
	fop (i,0,n) cin >> s[i];
	fop (i,0,m) cin >> t[i];
	cin >> tt;
	while (tt--) {
		cin >> tmp;
		tmp--;
		cout << s[tmp%n] << t[tmp%m] << endl;
	}
}