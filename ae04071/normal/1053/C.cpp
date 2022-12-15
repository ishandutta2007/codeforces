#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
typedef long long lli;
typedef pair<lli,lli> pll;

const lli mod=1e9+7;

int n,q,a[300001];

const int MAX=1<<18;
struct sum_seg{
	lli tr[MAX<<1];
	void upd(int cur,lli val) {
		tr[cur+=MAX] = val;
		cur>>=1;
		while(cur) {
			tr[cur] = tr[cur<<1] + tr[cur<<1|1];
			cur>>=1;
		}
	}
	lli sum(int l,int r) {
		lli res=0;
		l+=MAX;r+=MAX;
		while(l<=r) {
			if(l&1) res+=tr[l++];
			if(!(r&1)) res+=tr[r--];
			l>>=1; r>>=1;
		}
		return res;
	}
}sum;

struct td{
	lli lsum,rsum,lwsum,rwsum;
	td() {}
	td(lli a,lli b,lli c,lli d):lsum(a),rsum(b),lwsum(c),rwsum(d) {}
};
struct wsum_seg {
	lli ltr[MAX<<1],rtr[MAX<<1];
	pll upd(int cur,int s,int f,int idx) {
		if(f<idx || s>idx) return pll(ltr[cur],rtr[cur]);
		else if(s==f) return pll(0,0);
		else {
			int nx=cur<<1,md=(s+f)>>1,l=f-md;
			pll lv=upd(nx,s,md,idx),rv=upd(nx+1,md+1,f,idx);
			ltr[cur] = ((lv.first+rv.first)%mod + sum.tr[nx]%mod*(a[f]-l - a[md])%mod)%mod;
			rtr[cur] = ((lv.second+rv.second)%mod + sum.tr[nx+1]%mod*(a[md+1] - (a[s]+l))%mod)%mod;
			return pll(ltr[cur],rtr[cur]);
		}
	}
	td find(int cur,int s,int f,int l,int r) {
		if(f<l || s>r) return td(0,0,0,0);
		else if(l<=s && f<=r) return td(sum.tr[cur]%mod,sum.tr[cur]%mod,ltr[cur],rtr[cur]);
		else {
			int nx=cur<<1,md=(s+f)>>1,len=min(r,f)-md;
			if(r<=md) return find(nx,s,md,l,r);
			else if(l>=md+1) return find(nx+1,md+1,f,l,r);
			
	
			td lv=find(nx,s,md,l,r),rv=find(nx+1,md+1,f,l,r);
			td res;
			//printf("#%d %d %d %d\n",s,f,l,r);
			//printf("BASE : (%lld %lld, %lld %lld), (%lld %lld, %lld %lld)\n",lv.lwsum,lv.rwsum,lv.lsum,lv.rsum, rv.lwsum,rv.rwsum,rv.lsum,rv.rsum);
			//printf("LEN : %d\n",len);
			res.lwsum = ((lv.lwsum+rv.lwsum)%mod + lv.lsum%mod*(a[min(r,f)]-len - a[md])%mod)%mod;
			len=md-max(l,s)+1;
			res.rwsum = ((lv.rwsum+rv.rwsum)%mod + rv.rsum%mod*(a[md+1] - (a[max(l,s)]+len))%mod)%mod;
			res.lsum = (lv.lsum + rv.lsum)%mod;
			res.rsum = (lv.rsum + rv.rsum)%mod;
			//printf("VAL : %lld %lld, %lld %lld\n\n",res.lwsum,res.rwsum,res.lsum,res.rsum);
			
			return res;
		}
	}
}wsum;

int get_point(int s,int l,int r) {
	int lo=l-1,up=r+1;
	while(up-lo>1) {
		int md=(lo+up)>>1;
		if(a[md] <= s+(md-l)) lo=md;
		else up=md;
	}
	return lo;
}

int main() {
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=n+1;i<MAX;i++) a[i] = a[i-1]+1;
	for(int i=1;i<=n;i++) {
		lli val;
		scanf("%lld",&val);
		sum.upd(i,val);
		wsum.upd(1,0,MAX-1,i);
	}

	int x,y;
	while(q--) {
		scanf("%d%d",&x,&y);
		if(x<0) {
			x=-x;
			sum.upd(x,y);
			wsum.upd(1,0,MAX-1,x);
		} else {
			int lo=a[x-1], up=a[y+1];
			while(up-lo>1) {
				int md=(lo+up)>>1;
				int j=get_point(md,x,y);
				
				if(sum.sum(x,j)<=sum.sum(j+1,y)) lo=md;
				else up=md;
			}
			//printf("%d\n",get_point(14,1,5));
			int i=up,j=get_point(up,x,y);
			//printf("POS : %d %d\n",i,j);
			lli ans=0;
			if(j>=x) {
				td val = wsum.find(1,0,MAX-1,x,j);
				ans = (ans + val.lwsum%mod + val.lsum%mod*(i+j-x-a[j])%mod)%mod;
			}
			if(j+1<=y) {
				td val = wsum.find(1,0,MAX-1,j+1,y);
				ans = (ans + val.rwsum%mod + val.rsum%mod*(a[j+1]-(i+j-x+1))%mod)%mod;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}