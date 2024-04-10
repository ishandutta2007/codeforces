/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define sqr(a) ((a) * (a))
#define si short int
#define endl "\n"
#define mod % 1e9+7
const ld E = 1e-9;

ll A, B, s, t, m;

inline bool check(int r){
	ll a1 = (ll) A + B * (s - 1);
	ll an = (ll) A + B * (s + r - 1);
	ll sum = (ll) (a1 * 2 + B * r) * (r + 1) / 2;
	return (an <= t && sum <= t * m);
}

int get(){

	cin >> s >> t >> m;

	int l = 0, r = pow(10, 6);
	while(l + 1 < r){
		int x = (l + r) / 2;
		if(check(x))
			l = x;
		else
			r = x;
	}
	if(check(r))
		return r + s;
	if(check(l))
		return l + s;
	return -1;

}

int main() {

	int n;
	cin >> A >> B >> n;

	while(n--)
		cout << get() << endl;

}