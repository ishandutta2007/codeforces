
// Problem : D. Cleaning
// Contest : Codeforces - Codeforces Round #696 (Div. 2)
// URL : https://codeforces.com/contest/1474/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
long long pre[200005];
long long mnpre[200005];
long long mnsuf[2][200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i =1; i<=N; i++){
			cin >> arr[i];
			pre[i] = arr[i] - pre[i-1];
			mnpre[i] = min(mnpre[i-1], pre[i]);
		}
		if(pre[N] == 0 && *min_element(pre, pre+1+N) >= 0){
			cout << "YES\n";
			continue;
		}
		mnsuf[0][N+1] = mnsuf[1][N+1] = LLONG_MAX/2;
		for(int i = N; i; i--){
			mnsuf[0][i] = mnsuf[0][i+1];
			mnsuf[1][i] = mnsuf[1][i+1];
			mnsuf[i%2][i] = min(mnsuf[i%2][i], pre[i]);
		}
		if(pre[N]%2){
			cout << "NO\n";
			continue;
		}
		long long dif = (N%2 ? pre[N] : -pre[N])/2;
		//cout << dif << "\n";
		bool good = 0;
		for(int i = 1; i<N; i++){
			//cout << i << " " << dif << "\n";
			//cout << mnsuf[0][i+2] << " " << mnsuf[1][i+2] << "\n";
			if(arr[i] - arr[i+1] == dif){
				if(mnpre[i-1] >= 0 && mnsuf[i%2][i+2]-2*dif >= 0 && mnsuf[i%2^1][i+2]+2*dif >= 0){
					good |= (arr[i+1] - pre[i-1] >= 0 && arr[i] + pre[i-1] - arr[i+1] >= 0);
				}
			}
			dif *= -1;
		}
		cout << (good ? "YES" : "NO") << "\n";
	}
}