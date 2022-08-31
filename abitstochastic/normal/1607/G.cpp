#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 2e5 + 7; int T , N , M , A[_] , B[_];

signed main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; int suma = 0 , sumb = 0; for(int i = 1 ; i <= N ; ++i){cin >> A[i] >> B[i]; suma += A[i]; sumb += B[i];}
		int mx = suma - sumb , mn = suma - sumb;
		for(int i = 1 ; i <= N ; ++i){int p = min(A[i] , M) , q = min(B[i] , M); mn = mn - p + (M - p); mx = mx + q - (M - q);}
		int best = mn > 0 ? mn : (mx < 0 ? mx : (mx & 1)); cout << abs(best) << '\n';
		for(int i = 1 ; i <= N ; ++i){
			int p = min(A[i] , M) , q = min(B[i] , M) , delA = M - q , delB = q;
			int dlt = min((mx - best) / 2 , p - delA);
			mx -= 2 * dlt; delA += dlt; delB -= dlt; cout << delA << ' ' << delB << '\n';
		}
	}
	return 0;
}