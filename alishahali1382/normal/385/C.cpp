#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000010, MAX=10000010;

int n, m, l, r, x, cnt;
bool sieve[MAX];
int prime[1000000];
int f[MAX];
int tmp[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	for (int i=2; i*i<MAX; i++){
		if (sieve[i]) continue ;
		for (ll j=2*i; j<MAX; j+=i) sieve[j]=true;
	}
	for (int i=2; i<MAX; i++) if (!sieve[i]) prime[cnt++]=i;
	
	scanf("%d", &n);
	
	for (int i=0; i<n; i++){
		scanf("%d", &x);
		tmp[x]++;
		/*
		for (int j=0; j<cnt && x>1; j++){
			//cerr<<x<<endl;
			if (!sieve[x]){
				f[x]++;
				break ;
			}
			if (x%prime[j]) continue ;
			f[prime[j]]++;
			while (!(x%prime[j])) x/=prime[j];
		}*/
	}
	for (int i=0; i<cnt; i++){
		for (int j=prime[i]; j<MAX; j+=prime[i]) f[prime[i]]+=tmp[j];
	}
	
	
	//for (int i=1; i<=7; i++) cerr<<f[i]<<' ';cerr<<endl;
	
	for (int i=2; i<MAX; i++) f[i]+=f[i-1];
	scanf("%d", &m);
	while (m--){
		scanf("%d %d", &l, &r);
		l=min(10000000, l);
		r=min(10000000, r);
		printf("%d\n", f[r]-f[l-1]);
	}
	
	return 0;
}