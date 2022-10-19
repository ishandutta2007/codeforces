#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[100100];
int cnt[2][100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		memset(cnt, 0, sizeof(cnt));
		rep(i, n)
			cnt[i & 1][a[i]]++;
		int nowallcnt = 0;
		bool ok = 1;
		rep(i, 100001){
			int nowcnt[2] = {0, 0};
			rep(j, cnt[0][i]){
				nowcnt[nowallcnt]++;
				nowallcnt ^= 1;
			}
			rep(j, cnt[1][i]){
				nowcnt[nowallcnt]++;
				nowallcnt ^= 1;
			}
			if(nowcnt[0] != cnt[0][i] || nowcnt[1] != cnt[1][i]){
				ok = 0;
				break;
			}
		}
		if(ok)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}