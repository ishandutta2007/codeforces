#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200010;

ll n, k, ans;
ll A[MAXN];

map<ll, ll> mp1, mp2;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%lld %lld", &n, &k);	
	for (int i=0; i<n; i++){
		scanf("%lld", &A[i]);
		mp2[A[i]]++;
	}
	for (int i=0; i<n; i++){
		mp2[A[i]]--;
		if (!(A[i]%k)){
			ans+=mp1[A[i]/k]*mp2[A[i]*k];
		}
		mp1[A[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}