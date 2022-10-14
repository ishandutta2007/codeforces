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
#define endl '\n'

vector <int> build_fail (const string &s) {
	vector <int> f(s.length(), 0);
	int u = f[0] = -1;
	for (int i = 1; i < s.length(); ++i) {
		while (u != -1 and s[i] != s[u + 1]) u = f[u];
		if (s[i] == s[u + 1]) u++;
		f[i] = u;
	}
	return f;
}

int kmp (const string &a, const string &b) {
	vector <int> fail = build_fail(b);
	int u = -1;
	for (int i = max(int(a.size()) - int(b.size()), 0); i < a.length(); ++i) {
		while (u != -1 and a[i] != b[u + 1]) u = fail[u];
		if (a[i] == b[u + 1]) u++;
	}
	return u;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <string> ss(n);
    fop (i,0,n) cin >> ss[i];
    string s = "";
    fop (i,0,n) {
        int k = kmp(s, ss[i]);
        s += ss[i].substr(k + 1);
    }
    cout << s << endl;
}