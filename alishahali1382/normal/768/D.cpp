#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 1010;

ll n, k, ans, a, b, q;
ld p;
ll dp[MAXN];
ld prob[10000][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>k>>q;
	prob[0][0]=1;
	for (int i=1; i<10000; i++){
		for (int j=1; j<=k; j++){
			prob[i][j]=(ld) (prob[i-1][j]*j+prob[i-1][j-1]*(k-j+1))/k;
		}
	}
	//cerr<<prob[7176][990]<<endl;
	//cerr<<prob[7][k]<<endl;
	
	for (int i=0; i<q; i++){
		cin>>p;
		for (int i=1; i<=10000; i++){
			if (p-eps<=prob[i][k]*2000){
				cout<<i<<endl;
				break ;
			}
		}
	}
	return 0;
}