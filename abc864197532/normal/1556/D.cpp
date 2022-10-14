/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
	cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
	while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
	return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
	return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
	bool is = false;
	for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
	return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
	vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
	vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
	vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
	vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200001, logN = 20, K = 80000;

lli get(int i, int j) {
	lli ans = 0, tmp;
	cout << "or " << i + 1 << ' ' << j + 1 << endl;
	cin >> ans;
	cout << "and " << i + 1 << ' ' << j + 1 << endl;
	cin >> tmp;
	return ans + tmp; 
}

int main () {
	owo;
	int n, k;
	cin >> n >> k;
	lli a = get(0, 1), b = get(1, 2), c = get(0, 2);
	vector <lli> ans(n);
	ans[0] = (a + b + c) / 2 - b;
	ans[1] = (a + b + c) / 2 - c;
	ans[2] = (a + b + c) / 2 - a;
	for (int i = 3; i < n; ++i) {
		ans[i] = get(0, i) - ans[0];
	}
	sort(all(ans));
	cout << "finish " << ans[k - 1] << endl;
}