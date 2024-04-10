#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
pair<ld,ld>tr[4*LIM];
int lazy[4*LIM], N=1;
ld jaki(pair<ld,ld>x) {
	ld dl=sqrt(x.st*x.st+x.nd*x.nd);
	if(dl==0) return 0;
	ld s=x.nd/dl;
	ld a=asin(s);
	if(a>=0) {
		if(x.st<0) a=PI-a;
	} else {
		a*=-1;
		if(x.st<0) a=PI-a;
		a=2*PI-a;
	}
	return a;
}
pair<ld,ld>obroc(pair<ld,ld>x, int p) {
	p%=360;
	ld a=p; a*=PI/(long double)180;
	a+=jaki(x);
	if(a>2*PI) a-=2*PI;
	ld dl=sqrt(x.st*x.st+x.nd*x.nd);
	return {dl*cos(a), dl*sin(a)};
}
pair<ld,ld>przedluz(pair<ld,ld>x, ld y) {
	ld a=jaki(x);
	ld dl=sqrt(x.st*x.st+x.nd*x.nd); dl+=y;
	return {dl*cos(a), dl*sin(a)};
}
void spl(int v) {
	lazy[2*v]+=lazy[v];
	lazy[2*v+1]+=lazy[v];
	tr[2*v]=obroc(tr[2*v], lazy[v]);
	tr[2*v+1]=obroc(tr[2*v+1], lazy[v]);
	lazy[v]=0;
}
void upd1(int v, int l, int r, int x, ld p) {
	if(x<l || x>r) return;
	if(l==r) {
		tr[v]=przedluz(tr[v], p);
		return;
	}
	if(lazy[v]) spl(v);
	int mid=(l+r)/2;
	if(x<=mid) upd1(2*v, l, mid, x, p);
	else upd1(2*v+1, mid+1, r, x, p);
	tr[v]={tr[2*v].st+tr[2*v+1].st, tr[2*v].nd+tr[2*v+1].nd};
}
void upd2(int v, int l, int r, int a, int b, int p) {
	if(r<a || l>b) return;
	if(a<=l && r<=b) {
		lazy[v]+=p;
		tr[v]=obroc(tr[v], p);
		return;
	}
	if(lazy[v]) spl(v);
	int mid=(l+r)/2;
	upd2(2*v, l, mid, a, b, p);
	upd2(2*v+1, mid+1, r, a, b, p);
	tr[v]={tr[2*v].st+tr[2*v+1].st, tr[2*v].nd+tr[2*v+1].nd};
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	while(N<n) N*=2;
	rep(i, n) tr[N+i]={1, 0};
	for(int i=N-1; i; --i) tr[i]={tr[2*i].st+tr[2*i+1].st, tr[2*i].nd+tr[2*i+1].nd};
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c; --b;
		if(a==1) upd1(1, 0, N-1, b, c);
		else upd2(1, 0, N-1, b, n-1, 360-c);
		cout << fixed << setprecision(4) << tr[1].st << " " << tr[1].nd << '\n';
	}
}