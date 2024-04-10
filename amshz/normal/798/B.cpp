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

const ll MAX1 = 2e5+7,
	     MOD = 1e9+7;

ll n, ans, cnt, flag;
char ch;
string s[60], t;

string shift(string st, ll a){
	string ts = "";
	for (int i = a; i < st.size(); ++i){
		ts += st[i];
	}
	for (int i = 0; i < a; ++i){
		ts += st[i];
	}
	return ts;
}

int main(){
	fast_io;
	cin >> n;
	ans = 1e18;
	for (int i = 0; i < n; ++i)	cin >> s[i];
	for (int i = 0; i < s[0].size(); ++i){
		t = shift(s[0], i);
		cnt = 0;
		for (int j = 0; j < n; ++j){
			flag = 0;
			for (int k = 0; k < s[0].size(); ++k){
				if (shift(s[j], k) == t){
					cnt += k, flag = 1;
					break;
				}
			}
			if (!flag){
				cout << -1;
				return 0;
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans;
    return 0;
}
/*                     now or never                         */