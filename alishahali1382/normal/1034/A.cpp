#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 300010, MAX=15000000;

int n, k, g, cnt;
int A[MAXN];
bool sieve[MAX];
int help[MAX];
int prime[1000000];
int B[1000000];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	sieve[0]=sieve[1]=true;
	for (int i=2; i*i<MAX; i++){
		if (sieve[i]) continue ;
		for (ll j=2*i; j<MAX; j+=i) sieve[j]=true;
	}
	for (int i=2; i<MAX; i++) if (!sieve[i]) help[i]=cnt, prime[cnt++]=i;
	
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &A[i]);
		g=__gcd(A[i], g);
	}
	for (int i=0; i<n; i++) A[i]/=g;
	
	int ans=n, tmp, j;
	
	for (int i=0; i<n; i++){
		tmp=A[i];
		for (j=0; j<cnt && tmp>1; j++){
			if (!sieve[tmp]){
				B[help[tmp]]++;
				break ;
			}
			//cerr<<tmp<<' '<<prime[j]<<endl;;
			if (!(tmp%prime[j])){
				B[j]++;
				while (!(tmp%prime[j])) tmp/=prime[j];
			}
		}
	}
	for (int i=0; i<cnt; i++) ans=min(ans, n-B[i]);
	
	if (ans==n) ans=-1;
	printf("%d\n", ans);
	return 0;
}