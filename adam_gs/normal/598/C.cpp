#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define PI 3.14159265359
const int LIM=1e5+7;
pair<ld,int>T[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) {
		ll x, y;
		cin >> x >> y;
		ld r=x*x+y*y; r=sqrt(r);
		ld s=y; s/=r;
		T[i]={asin(s), i};
		if(T[i].st<0) {
			T[i].st*=-1;
			if(x<0) T[i].st=PI-T[i].st;
			T[i].st=2*PI-T[i].st;
		} else if(x<0) T[i].st=PI-T[i].st;
	}
	sort(T, T+n);
	int a=T[0].nd, b=T[n-1].nd;
	ld mi=T[0].st+2*PI-T[n-1].st;
	rep(i, n-1) {
		if(T[i+1].st-T[i].st<mi) {
			mi=T[i+1].st-T[i].st;
			a=T[i+1].nd;
			b=T[i].nd;
		}
	}
	cout << a+1 << " " << b+1 << '\n';
}