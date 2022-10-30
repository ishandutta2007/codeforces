#include<bits/stdc++.h>
#define N 100100
using namespace std;
typedef pair<long long,long long> pll;
int w;
pll plane[N],tmp[N];
bool cp_neg(pll a,pll b){
	if(a.second*b.second<0) a.first=-a.first,b.first=-b.first;
	return a.first*(b.second-w)<b.first*(a.second-w);
}
bool cp_pos(pll a,pll b){
	if(a.second*b.second<0) a.first=-a.first,b.first=-b.first;
	return a.first*(b.second+w)<b.first*(a.second+w);
}
bool cmp(pll a,pll b){
	return cp_pos(a,b) || !cp_pos(b,a)&&cp_neg(b,a);
}
long long msort(int l,int r){
	if(l+1>=r) return 0;
	int m=(l+r)/2;
	long long res=msort(l,m)+msort(m,r);
	int tl=l,tm=m,pos=l;
	while(tl<m || tm<r){
		if(tm==r || tl<m&&cp_neg(plane[tl],plane[tm])){
			res+=tm-m;
			tmp[pos++]=plane[tl++];
		}
		else{
			
			tmp[pos++]=plane[tm++];
		}
	}
	for(int i=l;i<r;i++) plane[i]=tmp[i];
	return res;
}
int main(){
	int n;
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;i++) scanf("%lld%lld",&plane[i].first,&plane[i].second);
	sort(plane,plane+n,cmp);
	//for(int i=0;i<n;i++) printf("%lld %lld\n",plane[i].first,plane[i].second);
	printf("%lld\n",msort(0,n));
	//for(int i=0;i<n;i++) printf("%lld %lld\n",plane[i].first,plane[i].second);
	return 0;
}