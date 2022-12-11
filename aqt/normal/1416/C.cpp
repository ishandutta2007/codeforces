
// Problem : C. XOR Inverse
// Contest : Codeforces - Codeforces Round #673 (Div. 1)
// URL : https://codeforces.com/contest/1416/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[300005];
int mp0[300005], mp1[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i= 1; i<=N; i++){
		cin >> arr[i];
	}
	long long ans = 0, x = 0;
	long long pre = 0;
	for(int b = 29; b>=0; b--){
		long long add0 = 0, add1 = 0;
		vector<int> cmp;
		for(int i = 1; i<=N; i++){
			cmp.push_back(arr[i]&pre);
			mp0[i-1] = mp1[i-1] = 0;
		}
		sort(cmp.begin(), cmp.end());
		cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
		for(int i = 1; i<=N; i++){
			int idx = lower_bound(cmp.begin(), cmp.end(), (arr[i]&pre)) - cmp.begin();
			if(arr[i]>>b&1){
				mp1[idx]++;
				add1 += mp0[idx];
			}
			else{
				mp0[idx]++;
				add0 += mp1[idx];
			}
		}
		if(add0 > add1){
			x += (1LL<<b);
		}
		pre += 1LL<<b;
		ans += min(add0, add1);
	}
	cout << ans << " " << x;
}