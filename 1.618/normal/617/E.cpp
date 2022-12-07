#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#define maxn 100005

using namespace std;
typedef long long ll;
int n,m,B,k,a[maxn],delta;
ll ans[maxn];
int cnt[2000005];
struct query{
	int l,r,id;
}q[maxn];
bool cmp(const query &x,const query &y){
	if((x.l - 1) / B == (y.l - 1) / B) return x.r < y.r; 
	return (x.l - 1) / B < (y.l - 1) / B;
}
int main(){
  scanf("%d%d%d",&n,&m,&k);
  B = (int)sqrt(n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  for(int i=1;i<=m;i++){
  	scanf("%d%d",&q[i].l,&q[i].r);
  	q[i].id = i;
  }
  sort(q+1,q+m+1,cmp);
  int lb = 1,rb = 0;
  ll res = 0;
	int tot = 0;
  for(int i=1;i<=m;i++){
  	while(rb < q[i].r){
			rb++;
  		tot ^= a[rb];
  		if(tot == k) res++;
  		res += cnt[k ^ tot ^ delta];
  		cnt[tot ^ delta]++;
  	}
  	while(lb < q[i].l){
  		res -= cnt[k ^ delta];
  		tot ^= a[lb];
  		delta ^= a[lb];
  		cnt[delta]--;
  		lb++;
  	}
  	while(rb > q[i].r){
  		cnt[tot ^ delta]--;
  		res -= cnt[k ^ tot ^ delta];
  		if(tot == k) res--;
  		tot ^= a[rb];
  		rb--;
  	}
  	while(lb > q[i].l){
  		lb--;
  		tot ^= a[lb];
  		cnt[delta]++;
  		delta ^= a[lb];
  		res += cnt[k ^ delta];
  	}
  	ans[q[i].id] = res;
  }
  for(int i=1;i<=m;i++){
  	printf("%I64d\n",ans[i]);
  }
  return 0;
}