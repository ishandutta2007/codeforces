#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 1000010;

ll t, a, b;

bool sieve[MAXN];
int prime[100000], cnt;

bool check(ll x){
	for (int i=2, j=1; i*i<=x && j<cnt; i=prime[j++]){
		if (x%i) continue ;
		//cerr<<x<<' '<<i<<endl;
		return false ;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i*i<=MAXN; i++){
		if (sieve[i]) continue ;
		for (int j=2*i; j<MAXN; j+=i) sieve[j]=1;
	}
	for (int i=2; i<MAXN; i++){
		if (sieve[i]) continue ;
		prime[cnt++]=i;
	}
	cin>>t;
	while (t--){
		cin>>a>>b;
		//cerr<<(a-b>1)<<' '<<check(a+b)<<endl;
		if (a-b>1 || !check(a+b)){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}