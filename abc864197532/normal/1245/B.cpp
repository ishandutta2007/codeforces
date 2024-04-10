#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
 
 
int main () {
	int t;
	cin >> t;
	vector <char> s1(100);
	while (t--) {
		int n, a, b, c, ans=0, a1=0, a2=0, a3=0;
		string s;
		cin >> n >> a >> b >> c >> s;
		fop (i,0,n) s1[i] = ' ';
		fop (i,0,n) {
			if (s[i] == 'R') a1++;
			if (s[i] == 'P') a2++;
			if (s[i] == 'S') a3++;
		}
		ans += min(a,a3) + min(b,a1) + min(c,a2);
		if (ans >= (n + 1) / 2) {
			cout << "YES" << endl;
			fop (i,0,n) {
				if (s[i] == 'R' and b) {
					b--;
					s1[i] = 'P';
				} if (s[i] == 'P' and c) {
					c--;
					s1[i] = 'S';
				} if (s[i] == 'S' and a) {
					a--;
					s1[i] = 'R';
				}
			}
			fop (i,0,n) {
				if (s1[i] == ' ') {
					if (a) {
						a--;
						s1[i] = 'R';
					} else if (b) {
						b--;
						s1[i] = 'P';
					} else if (c) {
						c--;
						s1[i] = 'S';
					}
				}
			}
			fop (i,0,n) cout << s1[i];
			cout << endl; 
		}
		else cout << "NO" << endl;
	}
}