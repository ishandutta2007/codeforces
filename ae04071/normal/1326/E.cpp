#include <bits/stdc++.h>
using namespace std;

int n,p[300001],q[300001],inv[300001];
struct seg_tr {
	const static int MAX = 1<<19;
	int tr[MAX<<1],lz[MAX<<1];
	void init() { for(int i=1;i<MAX+MAX;i++) tr[i] = 0, lz[i] = 0; }
	void push(int cur) {
		tr[cur] += lz[cur];
		if(cur<MAX) {
			lz[cur<<1] += lz[cur];
			lz[cur<<1|1] += lz[cur];
		}
		lz[cur] = 0;
	}
	int upd(int cur,int s,int f,int l,int r,int val) {
		push(cur);
		if(f<l || s>r) return tr[cur];
		else if(l<=s && f<=r) {
			lz[cur] += val; push(cur);
			return tr[cur];
		} else {
			int nx=cur<<1,md=(s+f)>>1;
			return tr[cur] = max(upd(nx,s,md,l,r,val), upd(nx+1,md+1,f,l,r,val));
		}
	}
	void upd(int l,int r,int val) {
		upd(1,0,MAX-1,l,r,val);
	}
}st;

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",p+i);
		inv[p[i]] = i;
	}

	int ans = n;
	st.upd(1, inv[n], 1);
	for(int i=1;i<=n;i++) {
		printf("%d ",ans);
		scanf("%d",q+i);
		st.upd(1, q[i],-1);
		st.push(1);
		while(ans>1 && st.tr[1] <= 0) {
			st.upd(1, inv[--ans], 1);
			st.push(1);
		}
	}
	
	return 0;
}