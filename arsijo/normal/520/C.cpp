/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
//#define x first
//#define y second
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define mod % 1000000007;

int main() {

	int n;
	cin >> n;

	int ar[4];
	ms(ar);

	string s;
	cin >> s;

	for(int i = 0; i < s.length(); i++)
		if(s[i] == 'A')
			ar[0]++;
		else if (s[i] == 'C')
			ar[1]++;
		else if (s[i] == 'G')
			ar[2]++;
		else
			ar[3]++;

	int t = 0, m = 0;
	for(int i = 0; i < 4; i++){
		if(ar[i] > m){
			m = ar[i];
			t = 1;
		}else if (ar[i] == m){
			t++;
		}
	}

	ll ans = 1;

	for(int i = 0; i < n; i++)
		ans = ans * t mod;

	cout << ans;

}