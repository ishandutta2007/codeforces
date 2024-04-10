#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define LL long long
#define st first
#define nd second
#define endl '\n'

using namespace :: std;

const int MAXN=200005;
LL n,q,f[MAXN*4],lz[MAXN*4],a[MAXN],b,c;

void push(int x,int l,int r) {
	if(lz[x]) {
		f[x]+=lz[x];
		if(l!=r) {
			lz[x*2]+=lz[x];
			lz[x*2+1]+=lz[x];
		}
		lz[x]=0;
	}

}

void upd(int x,int l,int r,int ll,int rr,LL val) {
	push(x,l,r);
	if(l>rr||r<ll)
		return;
	if(l>=ll&&r<=rr) {
		lz[x]+=val;
		push(x,l,r);
		return;
	}
	int md=(l+r)/2;
	upd(x*2,l,md,ll,rr,val);
	upd(x*2+1,md+1,r,ll,rr,val);
	f[x]=max(f[x*2],f[x*2+1]);

}

int que(int x,int l,int r) {
	push(x,l,r);
	if(f[x]<0)
		return -1;
	if(l==r) {
		if(f[x]==0)
			return l;
		else return -1;
	}
	int md=(l+r)/2,t;
	t=que(x*2,l,md);
	if(t!=-1) return t;
	return que(x*2+1,md+1,r);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		upd(1,1,n,i,i,a[i]);
		if(i!=n) upd(1,1,n,i+1,n,-a[i]);
	}
	for(int i=0;i<q;++i) {
		cin>>b>>c;
		if(b!=n) upd(1,1,n,b+1,n,a[b]-c);
		upd(1,1,n,b,b,c-a[b]);
		a[b]=c;
		cout<<que(1,1,n)<<endl;
	}
   return 0;

}