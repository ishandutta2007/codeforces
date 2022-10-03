#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-16;
const ll inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 1000010;

int n, m, d, x;
ld A[MAXN];

ld calc(ld x){
	ld mn=0, mx=0, tmp=0;
	for (int i=0; i<n; i++){
		tmp+=A[i]-x;
		mn=min(mn, tmp);
		mx=max(mx, tmp);
	}
	return mx-mn;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i];
	ld l=-inf, r=inf;
	for (int i=0; i<200; i++){
		ld m1=(2*l+1*r)/3;
		ld m2=(1*l+2*r)/3;
		if (calc(m1)<calc(m2)) r=m2;
		else l=m1;
	}
	cout<<setprecision(20)<<fixed<<calc(l)<<endl;
	return 0;
}