#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
typedef long long ll;
const ll rd = 987654321;
const int mx = 1<<17;
ll rdpw[mx], pwsum[mx];

struct ST{
	ll t[2*mx], d[mx];
	int rs[2*mx], ls[2*mx];
	void init(){
		rrep(i,1,mx) t[i] = t[2*i] + t[2*i+1];
		rep(i,0,mx) ls[mx+i] = i, rs[mx+i] = i+1;
		rrep(i,1,mx) ls[i] = ls[2*i], rs[i] = rs[2*i+1];
		fill(d,d+mx,-1);
	}
	void calc(int p){
		if(d[p] == -1) t[p] = t[2*p] + t[2*p+1];
		else t[p] = d[p]*(pwsum[rs[p]]-pwsum[ls[p]]);
	}
	void apply(int p, int dig){
		t[p] = dig*(pwsum[rs[p]] - pwsum[ls[p]]);
		if(p < mx) d[p] = dig;
	}
	void build(int l, int r){
		for(l+=mx,r+=mx-1; l > 1;){
			l /= 2, r /= 2;
			rrep(i,l,r+1) calc(i);
		}
	}
	void push(int l, int r){
		l += mx, r += mx;
		rrep(s,1,19) rep(i,l>>s,(r>>s)+1)
			if(d[i] != -1){
				apply(2*i, d[i]);
				apply(2*i+1, d[i]);
				d[i] = -1;
			}
	}
	void ass(int l, int r, int dig){
		push(l, l+1);
		push(r-1, r);
		for(int l1 = l+mx, r1 = r+mx; l1 < r1; l1 /= 2, r1 /= 2){
			if(l1%2) apply(l1++, dig);
			if(r1%2) apply(--r1, dig);
		}
		build(l, l+1);
		build(r-1, r);
	}
	ll que(int l, int r){
		push(l,l+1);
		push(r-1,r);
		ll ans = 0;
		for(l += mx, r += mx; l < r; l /= 2, r /= 2){
			if(l%2) ans += t[l++];
			if(r%2) ans += t[--r];
		}
		return ans;
	}
} w;

int main(){
	rdpw[0] = 1;
	pwsum[0] = 0;
	rep(i,1,mx){
		rdpw[i] = rd * rdpw[i-1];
		pwsum[i] = rdpw[i-1] + pwsum[i-1];
	}
	int n,m,k,l,r,d,ty;
	scanf("%d %d %d\n",&n,&m,&k);
	rep(i,0,n){
		char dig;
		scanf("%c",&dig);
		w.t[mx+i] = rdpw[i]*(dig-'0');
	}
	w.init();
	rep(_,0,m+k){
		scanf("%d%d%d%d",&ty,&l,&r,&d);
		--l;
		switch(ty){
			case 1:
				w.ass(l,r,d);
				break;
			case 2:
				ll sm = w.que(l,l+d);
				int rr = r - (r-l)%d;
				if(w.que(l, l+(r-l)%d)*rdpw[rr-l] != w.que(rr,r)){
					puts("NO");
					break;
				}
				ll bg = w.que(l,rr);
				if(bg*(rdpw[d]-1) != sm*(rdpw[rr-l]-1)) puts("NO");
				else {
					bool fl = 0;
					rep(i,0,5){
						int tst = l + rand()%(rr-l),
						    bas = l + (tst-l)%d;
						if(tst == bas) continue;
						w.push(tst,tst+1);
						w.push(bas,bas+1);
						fl |= w.t[mx+tst] != w.t[mx+bas]*rdpw[tst-bas];
						if(fl) break;
					}
					puts(fl ? "NO" : "YES");
				}
				break;
		}
	}
}