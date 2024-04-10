#include<bits/stdc++.h>
using namespace std;

const int P = 998244353;
int poww(long long a , int b){
	int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;
}
int N , arr[200003] , T;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; int cnt1 = 0 , cnt2 = 0;
		for(int i = 1 ; i <= N ; ++i){cin >> arr[i]; cnt1+=arr[i];}
		for(int i = N - cnt1 + 1 ; i <= N ; ++i) cnt2 += arr[i];
		int ans = 0;
		for(int i = cnt2 ; i < cnt1 ; ++i)
			ans = (ans + 1ll * (N * (N - 1ll) / 2) % P * poww(1ll * (cnt1 - i) * (cnt1 - i) % P , P - 2)) % P;
		cout << ans << endl;
	}
	return 0;
}