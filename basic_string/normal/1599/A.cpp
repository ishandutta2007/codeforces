#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, a[N];
string s;
int sum[M];
void change(int k, int l, int r, int a, int b, int c) {
	if (l == a && r == b) {
		sum[k] += c;
		return;
	}
	int mid = (l + r) / 2;
	if (b <= mid) change(LC, l, mid, a, b, c);
	else if (a > mid) change(RC, mid + 1, r, a, b, c);
	else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
}
int ask(int k, int l, int r, int a) {
	if (l == r) return sum[k];
	int mid = (l + r) / 2;
	if (a <= mid) return sum[k] + ask(LC, l, mid, a);
	else return sum[k] + ask(RC, mid + 1, r, a);
}
char fan(char x) {
	if (x == 'L') return 'R';
	return 'L';
}

int main()
{
	IO;
	cin >> n;
	repn(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	cin >> s;
	change(1, 1, n, 1, 1, 1);
	repn(i, 2, n) {
		if (s[i - 1] == s[i - 2]) {
			change(1, 1, n, 1, i - 1, 1);
			change(1, 1, n, i, i, 1);
		}
		else change(1, 1, n, i, i, i);
	}
	int a1 = ask(1, 1, n, 1);
	repn(i, 1, n) {
		int ans = ask(1, 1, n, i);
		cout << a[ans] << " ";
		if ((ans & 1) == (a1 & 1)) cout << s[0] << "\n";
		else cout << fan(s[0]) << "\n";
	}
	return 0;
}