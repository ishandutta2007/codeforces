#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, k;
string s;
int cnt[100100][26];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k >> s;
		rep(i, n) rep(c, 26) cnt[i][c] = 0;
		rep(i, n){
			rep(c, 26) cnt[i + 1][c] = cnt[i][c];
			cnt[i + 1][s[i] - 'a']++;
		}
		if(n % k != 0){
			cout << "-1" << endl;
			continue;
		}
		int k_lmt = 0;
		while(k_lmt < n) k_lmt += k;
		bool ok = 0;
		int sum_need = 0;
		rep(c, 26) sum_need += (k_lmt - cnt[n][c]) % k;
		if(sum_need == 0){
			cout << s << endl;
			continue;
		}
		for(int i = n - 1; i >= 0; i--){
			sum_need = 0;
			rep(c, 26) sum_need += (k_lmt - cnt[i][c]) % k;
			int old_need = sum_need;
			for(int c = s[i] - 'a' + 1; c < 26; c++){
				sum_need -= (k_lmt - cnt[i][c]) % k;
				sum_need += (k_lmt - (cnt[i][c] + 1)) % k;
				if(sum_need <= (n - i - 1)){
					cnt[i][c]++;
					rep(j, i) cout << s[j];
					cout << (char)(c + 'a');
					rep(j, (n - i - 1) - sum_need) cout << 'a';
					rep(nc, 26){
						rep(j, (k_lmt - cnt[i][nc]) % k) cout << (char)(nc + 'a');
					}
					cout << endl;
					ok = 1;
					break;
				}
				sum_need = old_need;
			}
			if(ok) break;
		}
		if(!ok) cout << "-1" << endl;
	}
	return 0;
}