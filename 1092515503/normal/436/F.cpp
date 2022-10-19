#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int BBB=316;
int n,m,w,A,BLK[100100],lp[100100],lim;
pair<int,int>p[100100];
int stk[100100],tp[100100],pt[100100],tag[100100],mxp;
ll val[100100],mx;
void INS(int a){
//	printf("INS:%d\n",a);
	for(int i=0;i<BLK[a];i++){
		tag[i]++;
		while(pt[i]<tp[i]&&val[stk[pt[i]]]+1ll*stk[pt[i]]*tag[i]<=val[stk[pt[i]+1]]+1ll*stk[pt[i]+1]*tag[i])
			pt[i]++;
		if(mx<=val[stk[pt[i]]]+1ll*stk[pt[i]]*tag[i])
			mx=val[stk[pt[i]]]+1ll*stk[pt[i]]*tag[i],mxp=stk[pt[i]];
	}
	for(int i=lp[BLK[a]];i<lp[BLK[a]+1];i++)val[i]+=1ll*tag[BLK[a]]*i;
	for(int i=lp[BLK[a]];i<=a;i++)val[i]+=i;
	tp[BLK[a]]=lp[BLK[a]]-1,pt[BLK[a]]=lp[BLK[a]];
	for(int i=lp[BLK[a]];i<lp[BLK[a]+1];i++){
		while(tp[BLK[a]]>lp[BLK[a]]){
			int k=stk[tp[BLK[a]]-1],j=stk[tp[BLK[a]]];
			if((val[j]-val[k])*(i-j)>(val[i]-val[j])*(j-k))break;
			tp[BLK[a]]--;
		}
		stk[++tp[BLK[a]]]=i;
	}
	tag[BLK[a]]=0;
	while(pt[BLK[a]]<tp[BLK[a]]&&val[stk[pt[BLK[a]]]]<=val[stk[pt[BLK[a]]+1]])pt[BLK[a]]++;
	if(mx<=val[stk[pt[BLK[a]]]])
		mx=val[stk[pt[BLK[a]]]],mxp=stk[pt[BLK[a]]];
}
int main(){
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].second,&p[i].first),
		m=max(m,p[i].first+1),A=max(A,p[i].second+2);
	sort(p+1,p+n+1);
	for(int i=0;i<A;i++)BLK[i]=i/BBB;
	lp[BLK[A]=lim=BLK[A-1]+1]=A;
	for(int i=0;i<lim;i++)lp[i]=i*BBB;
	for(int i=0;i<A;i++)stk[i]=i;
	for(int i=0;i<lim;i++)pt[i]=lp[i],tp[i]=lp[i+1]-1;
	for(int i=0,j=1;i<=m;i++){
		while(j<=n&&p[j].first<i)INS(p[j++].second);
		printf("%lld %d\n",mx+1ll*(n-j+1)*i*w,mxp);
	}
	return 0;
}