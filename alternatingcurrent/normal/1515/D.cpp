#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, l, r;
int cnt[200200];
int all;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> l >> r;
		rep(i, n) cnt[i] = 0;
		all = 0;
		rep(i, l){
			int col;
			cin >> col;
			col--;
			cnt[col]++, all++;
		}
		rep(i, r){
			int col;
			cin >> col;
			col--;
			cnt[col]--, all--;
		}
		int ans = 0;
		int free = 0;
		rep(col, n){
			if(cnt[col] > 0){
				if(all > 0){
					int num = min(all / 2, cnt[col] / 2);
					all -= num + num;
					ans += num;
					cnt[col] -= num + num;
				}
				if(free < 0){
					int num = min(-free, cnt[col]);
					cnt[col] -= num;
					free += num;
				}
				free += cnt[col];
				ans += cnt[col];
			} else {
				if(all < 0){
					int num = min(-all / 2, -cnt[col] / 2);
					all += num + num;
					ans += num;
					cnt[col] += num + num;
				}
				if(free > 0){
					int num = min(free, -cnt[col]);
					cnt[col] += num;
					free -= num;
				}
				free += cnt[col];
				ans -= cnt[col];
			}
		}
		cout << ans << endl;
	}
	return 0;
}