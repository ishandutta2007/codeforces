#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qabs(int a){
	return (a < 0) ? -a : a;
}

int T;
int n;
int a[30030];
int cnt[5];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		rep(i, n){
			cin >> a[i];
			cnt[a[i] % 3]++;
		}
		int target = n / 3;
		int mxpos = 0;
		if(cnt[1] > cnt[mxpos]) mxpos = 1;
		if(cnt[2] > cnt[mxpos]) mxpos = 2;
		if(cnt[(mxpos + 1) % 3] > target){
			cout << 2 * (cnt[mxpos] - target) + (cnt[(mxpos + 1) % 3] - target) << endl;
		} else {
			if(cnt[(mxpos + 2) % 3] > target){
				cout << 2 * (cnt[(mxpos + 2) % 3] - target) + (cnt[mxpos % 3] - target) << endl;
			} else {
				cout << 2 * (target - cnt[(mxpos + 2) % 3]) + (target - cnt[(mxpos + 1) % 3]) << endl;
			}
		}
	}
	return 0;
}