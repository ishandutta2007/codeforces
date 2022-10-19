#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 800800

typedef long long ll;
using namespace std;

int bit[maxn];

void bitu(int idx,int val){
	debug("bit[%d] += %d\n",idx,val);
	idx++;
	while(idx < maxn){
		bit[idx] += val;
		idx += idx&-idx;
	}
}

int bitq(int idx){
	debug("acc[%d] = ",idx);
	idx++;
	int ret = 0;
	while(idx){
		ret += bit[idx];
		idx -= idx&-idx;
	}
	debug("%d\n",ret);
	return ret;
}

int T[4*maxn];

void update(int init,int fim,int p,int pos,int val){
	
	if(init > pos || fim < pos)
		return;
	
	if(init == fim){
		T[p] = val;
		return;
	}
	
	int mid = (init+fim)/2;
	
	update(init,mid,2*p,pos,val);
	update(mid+1,fim,2*p+1,pos,val);
	
	T[p] = max(T[2*p],T[2*p+1]);
	
}

int query(int init,int fim,int p,int l,int r){
	
	if(init > r || fim < l)
		return 0;
		
	if(init >= l && fim <= r)
		return T[p];
		
	int mid = (init+fim)/2;
	
	return max(query(init,mid,2*p,l,r), query(mid+1,fim,2*p+1,l,r));
	
}

int v[maxn];
int qual[maxn];
int to[maxn];

int dpl[maxn];
int dpr[maxn];

vector<pii> ask[maxn];
vector<pii> answer[maxn];

int resp[maxn];

set<int> S[maxn];

main(){
	
	int n,q;
	scanf("%d%d",&n,&q);
	
	int N = n+q+3;
	
	vector<pii> vec;
	
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		vec.pb(pii(a,i));
	}
	
	for(int i=0;i<q;i++){
		int id, h;
		scanf("%d%d",&id,&h), id--;
		qual[i] = id;
		vec.pb(pii(h,n+i));
	}
	
	sort(vec.begin(), vec.end());
	
	int cur = 0;
	
	for(int i=0;i<vec.size();i++){	
	
		if(i && vec[i].first != vec[i-1].first)
			cur++;
			
		if(vec[i].second < n)
			v[vec[i].second] = cur;
		else
			to[vec[i].second-n] = cur;
			
	}
	
	for(int i=0;i<q;i++)
		ask[qual[i]].pb(pii(to[i],i));
		
	debug("compress ");
	for(int i=0;i<n;i++)
		debug("%d ",v[i]);
	debug("\n");
	
	for(int i=n-1;i>=0;i--){
		
		dpr[i] = 1 + query(0,N-1,1,v[i]+1,N-1);
		debug("max %d..%d = %d\n",v[i]+1,N-1,dpr[i]-1);
		
		for(int j=0;j<ask[i].size();j++){
			int u = 1 + query(0,N-1,1, ask[i][j].first+1, N-1);
			answer[i].pb(pii(-1,u));
		}
		
		update(0,N-1,1,v[i],dpr[i]);
		debug("%d := %d\n",v[i],dpr[i]);
		
	}
	
	for(int i=0;i<N;i++)
		update(0,N-1,1,i,0);
		
	for(int i=0;i<n;i++){
		
		dpl[i] = 1 + query(0,N-1,1,0,v[i]-1);
		
		for(int j=0;j<ask[i].size();j++){
			int u = 1 + query(0,N-1,1,0,ask[i][j].first-1);
			answer[i][j].first = u;
		}
		
		update(0,N-1,1,v[i],dpl[i]);
		
	}
	
	int lis = 0;
	
	for(int i=0;i<n;i++)
		lis = max(lis,dpr[i]);
	
	int first = n-1;
	for(int i=n-1;i>=0;i--)
		if(dpl[i] == lis)
			first = i;
	
	if(first != n-1){
		bitu(first+1,1);
		bitu(n,-1);
		debug("%d..%d is ok\n",first+1,n-1);
	}
	
	first = 0;
	
	for(int i=0;i<n;i++)
		if(dpr[i] == lis)
			first = i;
	
	bitu(0,1);
	bitu(first,-1);
	debug("0..%d is ok\n",first-1);
	
	debug("lis %d\n",lis);
	
	for(int i=0;i<n;i++)
		debug("%d dp %d %d\n",i,dpl[i],dpr[i]);
	
	vector<pii> vv;
	
	for(int i=0;i<n;i++)
		vv.pb(pii(v[i],i));
		
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	
	int ptr = 0;
	
	for(int i=0;i<n;i++){
		
		int p0 = ptr;
		while(ptr < n && vv[ptr].first == vv[p0].first)
			ptr++;
		
		for(int j=p0;j<ptr;j++){
			
			int pos = vv[j].second;
			int dp_pos = dpl[pos];
			int need = lis - dp_pos;
			if(S[need].size() == 0)
				continue;
			int big = *(--S[need].end());
			if(big-1 < pos+1)
				continue;
			bitu(pos+1,1);
			bitu(big,-1);
			debug("%d..%d is ok\n",pos+1,big-1);
		
		}
		
		for(int j=p0;j<ptr;j++)
			S[dpr[vv[j].second]].insert(vv[j].second);
			
	}
	
	
	for(int i=0;i<q;i++){
		int ans = lis-1;
		if(bitq(qual[i])){
			ans = lis;
			debug("%d happy (%d)\n",i,qual[i]);	
		}
		resp[i] = ans;
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<ask[i].size();j++){
			resp[ask[i][j].second] = max(resp[ask[i][j].second],answer[i][j].first+answer[i][j].second-1);
			debug("i = %d ot = %d %d\n",i,answer[i][j].first,answer[i][j].second);	
		}
	
	for(int i=0;i<q;i++)
		printf("%d\n",resp[i]);
		
}