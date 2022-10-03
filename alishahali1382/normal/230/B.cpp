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

ll n, ans;
ll A[MAXN];

bool sieve[MAXN];
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i*i<=MAXN; i++){
		if (sieve[i]) continue ;
		for (int j=2*i; j<MAXN; j+=i) sieve[j]=1;
	}
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		ll tmp=sqrt(A[i]);
		if (tmp*tmp==A[i] && A[i]!=1 && !sieve[tmp]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	//cout<<calc(3)<<endl;
	
	return 0;
}