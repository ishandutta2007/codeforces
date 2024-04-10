#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long LL;
const int N=1000005;
int n,a[N];
map<int,int> mp;
il int Max(ct p,ct q){return p>q?p:q;}
il int Min(ct p,ct q){return p<q?p:q;}
il void que(ct l,ct r,it &x,it &w){printf("? %d %d\n",l,r),fflush(stdout),scanf("%d%d",&x,&w);}
il void solve(ct l,ct r) {
	if(l>r) return;
	it x,w;que(l,r,x,w);
	if(r-l+1==w) {
	   for(it i=l;i<=r;++i) a[i] = x;
	   mp[x]=l;return;
	}
	auto p=mp.lower_bound(x);
	int pos=-1,a,b,L,R; 
	if (p!=mp.end()&&p->first == x) pos = p->second;
	else{
		--p;
		for(it i=Max(l, p->second +w);;i+=w) {
			que(i,i,a,b),assert(!mp[a]),mp[a] = i;
			if (a== x){pos = i; break;}
		}
	}
	que(Max(l,pos-w+1),pos,a,b);
	(a==x)?L=pos-b+1,R=pos-b+w:(que(pos, Min(pos +w - 1, r), a, b),L=pos+b-w,R=pos+b-1);
	for(it i=L;i<=R;++i) ::a[i] = x;
	solve(l,L-1),solve(R+1, r);
}
int main() {
	scanf("%d", &n),mp[0]=0,solve(1, n),putchar('!');
	for(it i=1;i<=n;++i) printf(" %d", a[i]);
	fflush(stdout);
	return 0;
}