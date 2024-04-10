
// Problem : D. Bear and Floodlight
// Contest : Codeforces - Codeforces Round #226 (Div. 2)
// URL : https://codeforces.com/contest/385/problem/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, L, R;
const long double PI = acosl(-1);
long double x[25], y[25];
long double ang[25];
long double dp[1<<20];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L >> R;
	for(int i =0 ; i<N; i++){
		cin >> x[i] >> y[i] >> ang[i];
		ang[i] *= PI/180.0;
	}
	fill(dp, dp+(1<<N), L);
	for(int m = 1; m<1<<N; m++){
		for(int n = 0; n<N; n++){
			if(m>>n&1){
				long double dis = sqrt(y[n]*y[n] + (dp[m^(1<<n)] - x[n]) * (dp[m^(1<<n)] - x[n]));
				long double alpha = acosl((x[n] - dp[m^(1<<n)] ) / dis);
				//cout << alpha << endl;
				//cout << ang[n] << endl;
				//cout << m << " " << alpha << " " << x[n]/dis << endl;
				//cout << alpha << " " << ang[n] << " " << PI << endl;
				
				if(alpha+ang[n] >= PI){
					cout << R-L << "\n";
					return 0;
				}
				
				long double beta = PI - alpha - ang[n];
				long double x = dis * (long double) (sinl(ang[n]) / sinl(beta));
				dp[m] = max(dp[m], dp[m^(1<<n)] + x);
				dp[m] = min(dp[m], (long double) (R));
			}
		}
		//cout << m << " " << dp[m] << "\n";
	}
	cout << setprecision(15) << dp[(1<<N)-1]-L << "\n";
}