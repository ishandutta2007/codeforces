#include<bits/stdc++.h>
using namespace std;

#define int long long
int N , A[1000003] , T , M;

signed main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		int L = 0 , x; for(int i = 1 ; i <= M ; ++i){cin >> x; L = __gcd(L , x);}
		int sum[2] = {0,0};
		for(int i = 1 ; i <= L ; ++i){
			int als = 0 , sign = 1 , mn = 1e9;
			for(int j = i ; j <= N ; j += L){
				als += abs(A[j]); sign *= A[j] ? abs(A[j]) / A[j] : 0;
				mn = min(mn , abs(A[j]));
			}
			sum[0] += als - 2 * (sign == -1) * mn;
			sum[1] += als - 2 * (sign == 1) * mn;
		}
		cout << max(sum[0] , sum[1]) << endl;
	}
	return 0;
}