
// Problem : D. Friends and Subsequences
// Contest : Codeforces - Codeforces Round #361 (Div. 2)
// URL : https://codeforces.com/contest/689/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
int brr[200005];
int mxtbl[20][200005];
int mntbl[20][200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		mxtbl[0][i] = arr[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> brr[i];
		mntbl[0][i] = brr[i];
	}
	for(int d = 1; d<20; d++){
		for(int n = 1; n+(1<<d)-1 <= N; n++){
			mxtbl[d][n] = max(mxtbl[d-1][n], mxtbl[d-1][n+(1<<(d-1))]);
			mntbl[d][n] = min(mntbl[d-1][n], mntbl[d-1][n+(1<<(d-1))]);
		}
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		int l = 1, r = i, lb = 0, ub = 0;
		while(l <= r){
			int mid = l+r>>1;
			int k = 31 - __builtin_clz(i - mid + 1);
			if(max(mxtbl[k][mid], mxtbl[k][i+1-(1<<k)]) >= min(mntbl[k][mid], mntbl[k][i+1-(1<<k)])){
				ub = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		l = 1;
		r = i;
		while(l <= r){
			int mid = l+r>>1;
			int k = 31 - __builtin_clz(i - mid + 1);
			if(max(mxtbl[k][mid], mxtbl[k][i+1-(1<<k)]) > min(mntbl[k][mid], mntbl[k][i+1-(1<<k)])){
				lb = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}			
		}
		ans += ub - lb;
	}
	cout << ans;
}