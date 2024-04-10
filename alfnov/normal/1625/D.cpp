#include<bits/stdc++.h>
using namespace std;
struct apple{
	int ss[2];
}tr[300005*33];
int zh;
int a[300005],tot=0;
map<int,int>mp,pm;
int queshi[300005];
vector<int>g[300005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(m==0){
		printf("%d\n",n);
		for(int i=1;i<=n;++i)printf("%d ",i);
		return 0;
	}
	for(int i=1;i<=n;++i)pm[a[i]]=i;
	int L=log2(m+0.5);
	for(int i=1;i<=n;++i){
		int ss=a[i]>>(L+1);
		int wz=mp[ss];
		if(!wz)wz=mp[ss]=++tot,queshi[tot]=ss;
		g[wz].emplace_back(a[i]&(((1u<<(L+1))-1)));
	}
	vector<int>se;
	m^=1<<L;
	for(int tt=1;tt<=tot;++tt){
		int ch=queshi[tt]<<(L+1);
		vector<int>g1,g2;
		zh=1;
		for(auto cu:g[tt]){
			if(cu&(1<<L))g1.emplace_back(cu^(1<<L));
			else{
				g2.emplace_back(cu);
				int r=1;
				for(int i=30;i>=0;--i){
					int zz=(cu>>i)&1;
					if(tr[r].ss[zz])r=tr[r].ss[zz];
					else{
						tr[r].ss[zz]=++zh;
						r=zh;
					}
				}
			}
		}
		if(!g1.size()){
			se.emplace_back(g2[0]^ch);
			for(int i=1;i<=zh;++i)tr[i].ss[0]=tr[i].ss[1]=0;
			continue;
		}
		if(!g2.size()){
			se.emplace_back(g1[0]^(1<<L)^ch);
			for(int i=1;i<=zh;++i)tr[i].ss[0]=tr[i].ss[1]=0;
			continue;
		}
		int flag=0;
		for(auto cu:g1){
			int r=1,a1=0,a2=0;
			for(int i=30;i>=0;--i){
				int zz=(cu>>i)&1;
				if(tr[r].ss[!zz]){
					a1|=1<<i,a2^=(!zz)*(1<<i);
					r=tr[r].ss[!zz];
				}else{
					a2^=(zz)*(1<<i);
					r=tr[r].ss[zz];
				}
			}
			if(a1>=m){
				se.emplace_back(cu^(1<<L)^ch);
				se.emplace_back(a2^ch);
				flag=1;
				break;
			}
		}
		if(!flag)se.emplace_back(g1[0]^(1<<L)^ch);
		for(int i=1;i<=zh;++i)tr[i].ss[0]=tr[i].ss[1]=0;
	}
	int aa=se.size();
	if(aa==1)printf("-1\n");
	else{
		cout<<aa<<endl;
		for(auto cu:se){
			printf("%d ",pm[cu]);
		}
	}
	return 0;
}