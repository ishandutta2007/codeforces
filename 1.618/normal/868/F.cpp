#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
#define maxn 100005
using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
const ll infll = 0x3f3f3f3f3f3f3f3fll;
typedef pair<int,int> P;
int n,k,a[maxn];
ll dp[2][maxn];
ll c2(ll x){//C(x,2)
	return x * (x - 1) >> 1;
}
int st,ed,cnt[maxn];
ll res;
void move(int l,int r){
	while(st < l){
		cnt[a[st]]--;
		res -= cnt[a[st]];
		st++;
	}
	while(st > l){
		st--;
		res += cnt[a[st]];
		cnt[a[st]]++;
	}
	while(ed < r){
		ed++;
		res += cnt[a[ed]];
		cnt[a[ed]]++;
	}
	while(ed > r){
		cnt[a[ed]]--;
		res -= cnt[a[ed]];
		ed--;
	}
}
void calc(int l,int r,int L,int R){
	int mid = (l + r) >> 1;
	ll minval = infll;
	int minpos = 0;
	for(int i=L;i<=R && i < mid;i++){
		move(i + 1,mid);
		if(dp[0][i] + res < minval){
			minval = dp[0][i] + res;
			minpos = i;
		}
	}
	dp[1][mid] = minval;
	if(mid != l) calc(l,mid - 1,L,minpos);
	if(mid != r) calc(mid + 1,r,minpos,R);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	st = ed = 1;
	cnt[a[1]]++;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0] = 0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<i;j++) dp[1][j] = infll;
		calc(i,n,0,n);
		for(int j=0;j<=n;j++) dp[0][j] = dp[1][j];
	}
	printf("%I64d\n",dp[0][n]);
	return 0;
}