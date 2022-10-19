#include <bits/stdc++.h>

#define ll long long

#define pb push_back

#define pii pair<int,int>

#define maxn 1001000

#define mod 1000000007

#define debug 



using namespace std;

int beg[maxn];
int v[maxn];
int ans[maxn];

int x[maxn];
int y[maxn];

int T[maxn];

vector<int> lst[maxn];

int qry(int idx){
	int r = 0;
	while(idx){
		r += T[idx];
		idx -= idx&-idx;
	}
	return r;
}

void upd(int idx,int val){
	while(idx < maxn){
		T[idx] += val;
		idx += idx&-idx;
	}
}

int search(int k){
	int ans = 0;
	for(int i=18;i>=0;i--){
		if(T[ans+(1<<i)] <= k){
			ans += (1<<i);
			k -= T[ans];
		}
	}
	return ans+1;
}

main(){

	int n,q;
	scanf("%d%d",&n,&q);

	int sz = 0;

	for(int i=1;i<=n;i++){
		scanf("%d",v+i);
		if(v[i] > i) beg[i] = -1;
		else {
			int need = i - v[i];
			if(need == 0) beg[i] = i;
			else if(need > sz) beg[i] = -1;
			else beg[i] = search(sz-need);
			if(beg[i]+1){
				sz++;
				upd(beg[i],1);
			}
		}
		if(beg[i]+1)
			lst[beg[i]].pb(i);
		debug("beg[%d] = %d\n",i,beg[i]);
	}

	memset(T,0,sizeof(T));

	vector<int> v;
	
	for(int i=0;i<q;i++){
		scanf("%d%d",x+i,y+i), v.pb(i);
		x[i]++;
		y[i] = n - y[i];
	}

	sort(v.begin(),v.end(),[](int i,int j){
		return x[i] > x[j];
	});

	int cur = n;
	for(int i : v){
		while(cur >= x[i]){
			for(int j : lst[cur]){
				upd(j,1);
			}
			cur--;
		}
		ans[i] = qry(y[i]) - qry(x[i]-1);
	}

	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]);

}