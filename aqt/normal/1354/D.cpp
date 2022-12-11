
// Problem : D. Multiset
// Contest : Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1354/problem/D
// Memory Limit : 28 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[1000005], qu[1000005];
int cnt[3];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int q = 1; q<=Q; q++){
		cin >> qu[q];
	}
	int l = 1, r = N;
	while(l <= r){
		int mid = l+r>>1;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i= 1; i<=N; i++){
			if(arr[i] == mid){
				cnt[1]++;
			}
			else if(arr[i] > mid){
				cnt[2]++;
			}
			else{
				cnt[0]++;
			}
		}
		for(int i = 1; i<=Q; i++){
			int q = qu[i];
			if(q < 0){
				if(cnt[0] >= -q){
					cnt[0]--;
				}
				else if(cnt[1] + cnt[0] >= -q){
					cnt[1]--;
				}
				else{
					cnt[2]--;
				}
			}
			else{
				if(q == mid){
					cnt[1]++;
				}
				else if(q > mid){
					cnt[2]++;
				}
				else{
					cnt[0]++;
				}
			}
		}
		if(cnt[1]){
			cout << mid << "\n";
			return 0;
		}
		else if(cnt[0]){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << 0;
}