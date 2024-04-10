#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
//#define x first
//#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ll MAX = 1000;
typedef ll array[MAX][MAX];
const ld E = 1e-11;

int b1[26], c1[26], ar[26];

int get() {
	int ans = INT_MAX;
	for (int i = 0; i < 26; i++)
		if (c1[i] != 0)
			ans = min(ans, ar[i] / c1[i]);
	//cout << ans << endl;
	return (ans == INT_MAX ? 0 : ans);
}

int main() {

	sync;

	string a, b, c;
	cin >> a >> b >> c;

	ms(ar);
	ms(b1);
	ms(c1);

	for(int i = 0; i < (int) a.length(); i++) {
		ar[a[i] - 'a']++;
	}
	for(int i = 0; i < (int) b.length(); i++) {
		b1[b[i] - 'a']++;
	}
	for(int i = 0; i < (int) c.length(); i++) {
		c1[c[i] - 'a']++;
	}
	int b2 = INT_MAX;
	for(int i = 0; i < 26; i++)
	if(b1[i] != 0)
	b2 = min(b2, ar[i] / b1[i]);
	//cout << b2 << endl;
	int ans = 0, b3 = 0, c3 = 0;
	for(int i = 0; i < b2; i++) {
		int g = i + get();
		if(g > ans) {
			ans = g;
			b3 = i;
			c3 = g - i;
			//cout << i << " " << g << " " << b3 << " " << c3 << endl;
		}
		for(int i = 0; i < 26; i++)
		ar[i] -= b1[i];
	}
	int g = b2 + get();
	if(g > ans) {
		ans = g;
		b3 = b2;
		c3 = g - b2;
	}
	ms(ar);
	for(int i = 0; i < (int) a.length(); i++) {
		ar[a[i] - 'a']++;
	}
	for(int i = 0; i < b3; i++){
		cout << b;
	}
	for(int i = 0; i < 26; i++)
		ar[i] -= b1[i] * b3;
	for(int i = 0; i < c3; i++){
		cout << c;
	}
	for(int i = 0; i < 26; i++)
		ar[i] -= c1[i] * c3;
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < ar[i]; j++)
			cout << (char) ('a' + i);
}