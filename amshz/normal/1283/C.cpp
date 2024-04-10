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
	     MOD = 998244353;

ll q, n, m, x, num[MAX1], ans[MAX1];
string s, t;
set <ll> st;

int main(){
	fast_io;
	cin >> n;
	for (int i = 1; i <= n; ++i)	st.insert(i);
	for (int i = 1; i <= n; ++i){
		cin >> num[i];
		st.erase(num[i]);
	}
	for (int i = n; i >= 1; --i){
		if (num[i]){
			ans[i] = num[i];
			continue;
		}
		auto it = st.begin();
		ans[i] = *it;
		st.erase(it);
	}
	ll flag = 0;
	for (int i = 1; i <= n; ++i){
		if (ans[i] == i){
			flag = i;
		}
	}
	if (flag){
		for (int i = 1; i <= n; ++i){
			if (!num[i]){
				swap(ans[i], ans[flag]);
				if (ans[i] != i && ans[flag] != flag){
					break;
				}
				swap(ans[i], ans[flag]);
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		if (ans[i] == i)	cout << 1/0 << endl;
	}
	for (int i = 1; i <= n; ++i)	cout << ans[i] << sep;
    return 0;
}
/*                        now or never                 */