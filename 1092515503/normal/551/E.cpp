#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,BLK[500100],BBB,tag[500100];
pair<int,int>p[500100];
signed main(){
	scanf("%lld%lld",&n,&m),BBB=sqrt(n*sqrt(log2(n)));
	BBB=max(BBB,1ll);
	for(int i=0;i<n;i++)scanf("%lld",&p[i].first),p[i].second=i,BLK[i]=i/BBB;
	for(int i=0;i<=BLK[n-1];i++)sort(p+i*BBB,p+min((i+1)*BBB,n));
	for(int tt=1,t1,t2,t3,t4;tt<=m;tt++){
		scanf("%lld",&t1);
		if(t1==1){
			scanf("%lld%lld%lld",&t2,&t3,&t4);
			t2--,t3--;
			if(BLK[t2]==BLK[t3]){
				for(int i=BBB*BLK[t2];i<min(BBB*(BLK[t2]+1),n);i++)if(p[i].second>=t2&&p[i].second<=t3)p[i].first+=t4;
				sort(p+BLK[t2]*BBB,p+min((BLK[t2]+1)*BBB,n));
			}else{
				for(int i=BBB*BLK[t2];i<min(BBB*(BLK[t2]+1),n);i++)if(p[i].second>=t2&&p[i].second<=t3)p[i].first+=t4;
				sort(p+BLK[t2]*BBB,p+min((BLK[t2]+1)*BBB,n));
				for(int i=BBB*BLK[t3];i<min(BBB*(BLK[t3]+1),n);i++)if(p[i].second>=t2&&p[i].second<=t3)p[i].first+=t4;
				sort(p+BLK[t3]*BBB,p+min((BLK[t3]+1)*BBB,n));
				for(int i=BLK[t2]+1;i<BLK[t3];i++)tag[i]+=t4;
			}
		}else{
			scanf("%lld",&t2);
			int mn=-1,mx=-1;
			for(int i=0;i<=BLK[n-1];i++){
				int pos=lower_bound(p+i*BBB,p+min((i+1)*BBB,n),make_pair(t2-tag[i],0ll))-p;
//				printf("%d\n",pos);
				if(pos==min((i+1)*BBB,n))continue;
				if(p[pos].first!=t2-tag[i])continue;
				mn=p[pos].second;
				break;
			}
			for(int i=BLK[n-1];i>=0;i--){
				int pos=lower_bound(p+i*BBB,p+min((i+1)*BBB,n),make_pair(t2-tag[i]+1,0ll))-p;
				if(pos==i*BBB)continue;
				pos--;
				if(p[pos].first!=t2-tag[i])continue;
				mx=p[pos].second;
				break;
			}
			if(mn==-1)puts("-1");
			else printf("%lld\n",mx-mn);
		}
	}
//	for(int i=0;i<n;i++)printf("%lld %lld\n",p[i].first,p[i].second);
	return 0;
}