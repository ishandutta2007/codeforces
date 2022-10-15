/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("input.txt", "w", stdout);
#define ll long long
//#define x first
//#define y second
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

struct f{
	ll a;
	char c;
	f(ll d, char g){
		a = d;
		c = g;
	}
};

bool operator==(f a, f b){
	return (a.a == b.a && a.c == b.c);
}

bool operator<(f a, f b){
	return (a.a == b.a ? a.c < b.c : a.a < b.a);
}

int main() {

	sync;

	//output;
	//cout << 100000 << endl;
	//for(int i = 1; i <= 3; i++){
	//	for(int j = i; j <= 100000; j++)
	//		cout << j << " ";
	//	cout << endl;
//	}

	//input;

	ll ar[26];
	ll ans = 0;
	for(int i = 0; i < 26; i++){
		cin >> ar[i];
	}
	map<f, int> m;
	string s;
	cin >> s;
	ll a = 0;
	for(int i = 0; i < s.length() - 1; i++){
		a += ar[s[i] - 'a'];
		//cout << a << " " << s[i] << " " << m[f(a, s[i])] << endl;
		m[f(a, s[i])]++;
		ans += m[f(a, s[i + 1])];
	}

	cout << ans;

}