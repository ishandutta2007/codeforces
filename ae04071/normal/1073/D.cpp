#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n;
pli a[200001];

const int MAX=1<<18;
struct seg_tr{
	lli tr[MAX<<1];
	lli upd(int cur,int s,int f,int idx,lli val) {
		if(f<idx || s>idx) return tr[cur];
		else if(s==f) return tr[cur]=val;
		else {
			int nx=cur<<1,md=(s+f)>>1;
			return tr[cur]=upd(nx,s,md,idx,val)+upd(nx+1,md+1,f,idx,val);
		}
	}
	lli sum(int cur,int s,int f,int l,int r){
		if(l>r) return 0;
		if(f<l || s>r) return 0;
		else if(l<=s && f<=r) return tr[cur];
		else {
			int nx=cur<<1,md=(s+f)>>1;
			return sum(nx,s,md,l,r)+sum(nx+1,md+1,f,l,r);
		}
	}
	int kth(int cur,int s,int f,lli val) {
		if(s==f) return s;
		else {
			int nx=cur<<1,md=(s+f)>>1;
			if(tr[nx]<=val) return kth(nx+1,md+1,f,val-tr[nx]);
			else return kth(nx,s,md,val);
		}
	}
}tr,ctr;

int main() {
	lli t;
	scanf("%d%lld",&n,&t);
	for(int i=0;i<n;i++) {
		scanf("%lld",&a[i].fi);
		tr.upd(1,0,MAX-1,i,a[i].fi);
		ctr.upd(1,0,MAX-1,i,1);
		a[i].se=i;
	}

	lli ans=0;
	int cur=0;
	sort(a,a+n);
	for(int i=n-1,j;i>=0;i=j) {
		ans += (t/tr.tr[1])*ctr.tr[1];
		t%=tr.tr[1];

		int idx=tr.kth(1,0,MAX-1,t+tr.sum(1,0,MAX-1,0,cur-1));
		if(idx>=n) {
			ans += ctr.sum(1,0,MAX-1,cur,n-1);
			t-=tr.sum(1,0,MAX-1,cur,n-1);
			idx=tr.kth(1,0,MAX-1,t);

			ans+=ctr.sum(1,0,MAX-1,0,idx-1);
			t-=tr.sum(1,0,MAX-1,0,idx-1);
			cur=idx;
		} else {
			t-=tr.sum(1,0,MAX-1,cur,idx-1);
			ans+=ctr.sum(1,0,MAX-1,cur,idx-1);
			cur=idx;
		}

		for(j=i;j>=0 && a[i].fi==a[j].fi;j--) {
			tr.upd(1,0,MAX-1,a[j].se,0);
			ctr.upd(1,0,MAX-1,a[j].se,0);
		}
	}
	printf("%lld\n",ans);

	return 0;
}