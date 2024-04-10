#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 510;

ll n, m, tmp, cnt, ans=inf;
ll A[MAXN][MAXN];

bool sieve[200010];
int prime[100000];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<=200000; i++){
		if (sieve[i]) continue ;
		for (int j=2*i; j<=200000; j+=i){
			sieve[j]=true;
		}
	}
	for (int i=2; i<=200000; i++){
		if (!sieve[i]) prime[cnt++]=i;
	}
	
	cin>>n>>m;
	for (int i=0; i<n; i++){
		tmp=0;
		for (int j=0; j<m; j++){
			cin>>A[i][j];
			A[i][j]= *lower_bound(prime, prime+cnt, A[i][j]) - A[i][j];
			tmp+=A[i][j];
		}
		ans=min(ans, tmp);
	}
	for (int j=0; j<m; j++){
		tmp=0;
		for (int i=0; i<n; i++) tmp+=A[i][j];
		ans=min(ans, tmp);
	}
	cout<<ans<<endl;
	
	return 0;
}