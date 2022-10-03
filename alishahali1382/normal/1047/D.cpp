#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

ll n, m;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%lld %lld", &n, &m);
	if (n<3 && m<3){
		printf("0\n");
		return 0;
	}
	if (n==1 || m==1){
		if (m==1) swap(n, m); // now: n=1
		
		if (m%6==0) printf("%lld\n", m);
		if (m%6==1) printf("%lld\n", m-1);
		if (m%6==2) printf("%lld\n", m-2);
		if (m%6==3) printf("%lld\n", m-3);
		if (m%6==4) printf("%lld\n", m-2);
		if (m%6==5) printf("%lld\n", m-1);
		return 0;
	}
	if (n%6==0 || m%6==0){
		printf("%lld\n", n*m);
		return 0;
	}
	if (n%2==0 && m%2==0){
		printf("%lld\n", n*m);
		return 0;
	}
	if (n==2 || m==2){
		if (m==2) swap(n, m);
		if (m==3 || m==7) printf("%lld\n", n*m-2);
		else printf("%lld\n", n*m);
		return 0;
	}
	if (n%2==0 || m%2==0){
		printf("%lld\n", n*m);
		return 0;
	}
	printf("%lld\n", n*m-1);

	return 0;
}