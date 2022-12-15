#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;

const int MAX=1<<20;
vector<int> pa;
struct seg{
	pll tr[MAX<<1];
	void upd(int cur,int s) {
		lli ad=1ll*pa[cur]*s;
		cur+=MAX;
		while(cur) {
			tr[cur].fi+=ad; tr[cur].se+=s;
			cur>>=1;
		}
	}
	lli kth(int cur,int s,int f,int k) {
		if(s==f) {
			if(s<sz(pa)) return 1ll*min(k*1ll,tr[cur].se)*pa[s];
			else return 0ll;
		}
		else {
			int nx=cur<<1,md=(s+f)>>1;
			//printf("@%lld %lld\n",tr[nx].se,tr[nx].fi);
			if(tr[nx].se>k) return kth(nx,s,md,k);
			else return kth(nx+1,md+1,f,k-tr[nx].se)+tr[nx].fi;			
		}
	}
}tr;

struct td{
	int idx,p,c;
	td() {}
	td(int idx,int p,int c):idx(idx),p(p),c(c){}
	bool operator<(const td &rhs)const {
		return idx<rhs.idx;
	}
};
vector<td> qa;
int n,m,k;

int main() {
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<m;i++) {
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		qa.push_back(td(a,d,c));
		qa.push_back(td(b+1,d,-c));
		pa.push_back(d);
	}	
	sort(pa.begin(),pa.end());
	pa.erase(unique(pa.begin(),pa.end()),pa.end());
	sort(qa.begin(),qa.end());

	lli ans=0;
	int j=0;
	for(int i=1;i<=n;i++) {
		while(j<sz(qa) && qa[j].idx<=i) {
			int idx=lower_bound(pa.begin(),pa.end(),qa[j].p)-pa.begin();
			tr.upd(idx,qa[j].c);
			j++;
		}
		ans+=tr.kth(1,0,MAX-1,k);
	}
	printf("%lld\n",ans);

	return 0;
}