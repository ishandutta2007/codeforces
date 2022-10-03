#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-16;
const ld inf=1e18+100;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 1000010;

int n, m, d, x;
ld A[2][2];

ld ternary(ld x, ld a, ld b){
	ld l=0, r=inf;
	for (int i=0; i<200; i++){
		ld m1=(5*l+4*r)/9;
		ld m2=(4*l+5*r)/9;
		//cerr<<l<<' '<<r<<endl<<m1<<' '<<m2<<endl<<endl;
		if (max(abs(a-m1), abs(b-x/m1))<max(abs(a-m2), abs(b-x/m2))) r=m2;
		else l=m1;
	}
	ld res=max(abs(a-l), abs(b-x/l));
	l=-inf;
	r=0;
	for (int i=0; i<200; i++){
		ld m1=(5*l+4*r)/9;
		ld m2=(4*l+5*r)/9;
		//cerr<<l<<' '<<r<<endl<<m1<<' '<<m2<<endl<<endl;
		if (max(abs(a-m1), abs(b-x/m1))<max(abs(a-m2), abs(b-x/m2))) r=m2;
		else l=m1;
	}
	res=min(max(abs(a-l), abs(b-x/l)), res);
	return res;
}

ld calc(ld x){
	return max(ternary(x, A[0][0], A[1][1]), ternary(x, A[0][1], A[1][0]));
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>A[0][0]>>A[0][1]>>A[1][0]>>A[1][1];  // A[0][0]*A[0][1] = A[1][0]*A[1][1]
	if (A[0][0]>A[1][1]) swap(A[0][0], A[1][1]);
	if (A[0][1]>A[1][0]) swap(A[0][1], A[1][0]);
	
	ld l=-inf, r=inf;
	for (int i=0; i<300; i++){
		ld m1=(5*l+4*r)/9;
		ld m2=(4*l+5*r)/9;
		if (calc(m1)<calc(m2)) r=m2;
		else l=m1;
	}
	cout<<setprecision(10)<<fixed<<calc(l)<<endl;
	
	//cerr<<calc(5.04)<<endl;
	//cerr<<ternary(5.04, 2, 3)<<endl;
	//cerr<<ternary(5.04, 1, 4)<<endl;
	
	return 0;
}