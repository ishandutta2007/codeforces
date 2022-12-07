#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 200005
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct point{
	bool l;
	ll pos;
};
vector <point> po;
ll po2[maxn * 2];
int lc[maxn * 2],rc[maxn * 2],k;
bool cmp(const point &x,const point &y){
	return x.pos < y.pos;
}
int n;
P seg[maxn];
ll cnt[maxn],stk;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d%I64d",&seg[i].first,&seg[i].second);
		point p1,p2;
		p1.l = true,p1.pos = seg[i].first,p2.l = false,p2.pos = seg[i].second;
		po.pb(p1);
		po.pb(p2);
	}
	sort(po.begin(),po.end(),cmp);
	int lcnt = 0,rcnt = 0;
	ll lst = -1;
	for(int i=0;i<po.size();i++){
		if(po[i].pos > lst){
			if(lst != -1){
				k++;
				po2[k] = lst;
				lc[k] = lcnt;
				rc[k] = rcnt;
			}
			lst = po[i].pos;
			lcnt = rcnt = 0;
			if(po[i].l) lcnt++;
			else rcnt++;
		}else{
			if(po[i].l) lcnt++;
			else rcnt++;
		}
	}
	k++;
	po2[k] = lst;
	lc[k] = lcnt;
	rc[k] = rcnt;
	for(int i=1;i<=k;i++){
		stk += lc[i];
		cnt[stk]++;
		if(i == k) break;
		stk -= rc[i];
		cnt[stk] += po2[i+1] - po2[i] - 1;
	}
	for(int i=1;i<=n;i++){
		printf("%I64d",cnt[i]);
		if(i == n) printf("\n");
		else printf(" ");
	}
	return 0;
}