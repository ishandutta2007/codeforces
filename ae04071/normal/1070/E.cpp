#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;

int n,m,a[200001];
lli t;

const int MAX=1<<18;
struct seg{
	int tr[MAX<<1];
	int s;
	void init() {
		s=1;
		while(s<n+1) s*=2;
		for(int i=0;i<s+s;i++)
			tr[i]=0;		
	}
	void upd(int cur,int val) {
		cur+=s;
		while(cur) {
			tr[cur]+=val; 
			cur>>=1;
		}
	}
	int sum(int l,int r) {
		int res=0;
		l+=s; r+=s;
		while(l<=r) {
			if(l&1) {
				res+=tr[l];
				l++;
			}
			if(!(r&1)) {
				res+=tr[r];
				r--;
			}
			l>>=1; r>>=1;
		}
		return res;
	}
	int kth(int cur,int s,int f,int k) {
		if(s==f) return s;
		else {
			int nx=cur<<1,md=(s+f)>>1;
			if(tr[nx]>=k) return kth(nx,s,md,k);
			else return kth(nx+1,md+1,f,k-tr[nx]);
		}
	}
	int kth(int k) {
		if(k<=0) return 0;
		else return kth(1,0,s-1,k);
	}

}tc;
struct seg_tr{
	lli tr[200001];
	void init() {
		for(int i=0;i<=n;i++) 
			tr[i]=0;
	}
	void upd(int cur,lli val) {
		while(cur<=n) {
			tr[cur]+=val; cur+=cur&-cur;
		}
	}
	lli sum(int cur) {
		lli res=0;
		while(cur) {
			res+=tr[cur];
			cur-=cur&-cur;
		}
		return res;
	}
}ts;

bool check(int c) {
	int ss=tc.sum(1,c);
	int v=ss%m;
	if(v==0) v=m;

	int k=tc.kth(ss-v);
	return ts.sum(k)+ts.sum(c)<=t; 
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		vector<pii> arr;
		scanf("%d%d%lld",&n,&m,&t);

		ts.init(); 
		tc.init();

		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=1;i<=n;i++) 
			arr.push_back(pii(a[i],i));
		sort(arr.begin(),arr.end());

		int ans=0,ad=1;
		for(int i=0,j;i<n;i=j) {
			for(j=i;j<n && arr[i].fi==arr[j].fi;j++) {
				ts.upd(arr[j].se,arr[j].fi);
				tc.upd(arr[j].se,1);
			}
			int lo=0,up=n+1;
			while(up-lo>1) {
				int md=(lo+up)>>1;
				if(check(md)) lo=md;
				else up=md;
			}
			int val=tc.sum(1,lo);
			if(ans<val) {
				ans=val;
				ad=arr[i].fi;
			}
		}
		printf("%d %d\n",ans,ad);
	}
	return 0;
}