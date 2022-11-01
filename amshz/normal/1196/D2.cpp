#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef string          str;
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAX1 = 5e5 + 7;

ll a, b, c, T, d, e, x1, y1, x2, y2, l, r, x, y, z, mid, cnt, flag, num[3][MAX1], mod = 1e9+7;
vector <ll> vec;
char q[3] = {'R', 'G', 'B'};
string s, t, rgb[3];

int main(){
	cin >> T;
	for (int k = 0; k < T; ++k){
		cin >> a >> b >> s;
		rgb[0] = "";
		rgb[1] = "";
		rgb[2] = "";
		for (int i = 0; i < a; ++i){
			rgb[0] += q[i%3];
			rgb[1] += q[(i+1)%3];
			rgb[2] += q[(i+2)%3];
		}
		for (int i = 0; i < a; ++i){
			if (rgb[0][i] == s[i])	num[0][i] = 1, num[1][i] = 0, num[2][i] = 0;
			if (rgb[1][i] == s[i])	num[0][i] = 0, num[1][i] = 1, num[2][i] = 0;
			if (rgb[2][i] == s[i])	num[0][i] = 0, num[1][i] = 0, num[2][i] = 1;
		}
		cnt = 0;
		x = 0;
		for (int i = 0; i < b; ++i)	cnt += num[0][i];
		x = max(x, cnt);
		for (int i = b; i < a; ++i){
			cnt += num[0][i]-num[0][i-b];
			x = max(x, cnt);
		}
		cnt = 0;
		for (int i = 0; i < b; ++i)	cnt += num[1][i];
		x = max(x, cnt);
		for (int i = b; i < a; ++i){
			cnt += num[1][i]-num[1][i-b];
			x = max(x, cnt);
		}
		cnt = 0;
		for (int i = 0; i < b; ++i)	cnt += num[2][i];
		x = max(x, cnt);
		for (int i = b; i < a; ++i){
			cnt += num[2][i]-num[2][i-b];
			x = max(x, cnt);
		}
		cout << b-x << endl;
	}
    return 0;
}
/*                          now or never                         */