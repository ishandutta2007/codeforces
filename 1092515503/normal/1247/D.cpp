#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
int n,m,ans,rev=1,tmp,occ[100100],POW[100100];
vector<pii>v;
int pov(int x,int y){
	if(!y)return 1;
	int tmp=pov(x,y>>1);
	if(tmp==-1)return -1;
	tmp*=tmp;
	if(y&1)tmp*=x;
	if(tmp>1e5)return -1;
	return tmp;
}
bool sol(int ip){
	v.clear();
	rev=1;
	for(int i=2;i*i<=ip;i++){
		if(ip%i)continue;
		v.pb(mp(i,0));
		while(!(ip%i))v[v.size()-1].y++,ip/=i;
	}
	if(ip!=1)v.pb(mp(ip,1));
	for(int i=0;i<v.size();i++){
//		printf("(%d %d)",v[i].x,v[i].y);
		v[i].y%=m;
		int tp=pov(v[i].x,(m-v[i].y)%m);
		if(tp==-1)return false;
		rev*=tp;
		if(rev>1e5)return false;
	}
//	puts("");
	return true;
}
signed main(){
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;;i++){
		POW[i]=pov(i,m);
		if(POW[i]==-1)break;
	}
	for(int i=1;i<=n;i++){
		scanf("%I64d",&tmp);
		if(!sol(tmp)){
			occ[tmp]++;
			continue;
		}
//		printf("%d\n",rev);
		for(int j=1;j<=n&&POW[j]!=-1&&rev*POW[j]<=1e5;j++)ans+=occ[rev*POW[j]];
		occ[tmp]++;
	}
	printf("%I64d\n",ans);
	return 0;
}