#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 3e5 + 5;
const int inf = 1e9;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	string s, t;
	cin >> n >> k;
	cin >> s >> t;
	if (k == 1)
		return cout << n << endl, 0;
	k -= 2;
	
	bool found = 0;
	ll ans = 0, tmp = 1;
	for (int i = 0; i < n; i++){
		if (found == 0){
			if (s[i] != t[i]){
				found = 1;
				tmp ++;
			}
		}
		else{
			if (tmp - 2 >= k){
				tmp += k;
				k = 0;
			}
			else{
				k -= (tmp - 2);
				tmp += (tmp - 2);
				if (s[i] == 'a' and k){
					k --;
					tmp ++;
				}
				if (t[i] == 'b' and k){
					k --;
					tmp ++;
				}
			}
		}
		ans += tmp;
	}
	cout << ans << endl;
}