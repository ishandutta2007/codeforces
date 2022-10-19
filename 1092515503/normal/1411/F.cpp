#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int T,n,p[1001000],pro,res;
vector<int>v[3];
bool vis[1001000];
void mina(){
	scanf("%d",&n),pro=1,res=0;
	for(int i=0;i<3;i++)v[i].clear();
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),vis[i]=false;
	for(int i=1;i<=n;i++)if(!vis[i]){
		int sz=0;
		for(int j=i;!vis[j];j=p[j])vis[j]=true,sz++;
		v[sz%3].push_back(sz);
	}
	if(n%3==0){
		for(int i=1;i<=n/3;i++)pro=3ll*pro%mod;
		for(auto x:v[0])res+=x/3-1;
		for(auto x:v[1])res+=x/3;
		for(auto x:v[2])res+=x/3;
		int X=v[1].size(),Y=v[2].size(),Z=min(X,Y);
//		printf("GUGUGU:%d,%d,%d,%d\n",X,Y,Z,res);
		X-=Z,Y-=Z;
		res+=Z+X/3*2+Y;
	}
	if(n%3==2){
		for(int i=1;i<=n/3;i++)pro=3ll*pro%mod;pro=2ll*pro%mod;
		for(auto x:v[0])res+=x/3-1;
		for(auto x:v[1])res+=x/3;
		for(auto x:v[2])res+=x/3;
		int X=v[1].size(),Y=v[2].size();
		if(Y)Y--;else X-=2,res++;
		int Z=min(X,Y); 
		X-=Z,Y-=Z;
		res+=Z+X/3*2+Y;
	}
	if(n%3==1){
		for(int i=1;i<=n/3-1;i++)pro=3ll*pro%mod;pro=4ll*pro%mod;
		res=0x3f3f3f3f;
		int _X=v[1].size(),_Y=v[2].size();
		if(_Y>=2){
			int X=_X,Y=_Y-2;
			int Z=min(X,Y); 
			X-=Z,Y-=Z;
			res=min(res,Z+X/3*2+Y);
		}
		if(_X&&*max_element(v[1].begin(),v[1].end())>=4){
			int X=_X-1,Y=_Y;
			int Z=min(X,Y); 
			X-=Z,Y-=Z;
			res=min(res,Z+X/3*2+Y-1);
		}
		if(_Y&&_X>=2){
			int X=_X-2,Y=_Y-1;
			int Z=min(X,Y); 
			X-=Z,Y-=Z;
			res=min(res,Z+X/3*2+Y+1);
		}
		if(_X>=4){
			int X=_X-4,Y=_Y;
			int Z=min(X,Y);
			X-=Z,Y-=Z;
			res=min(res,Z+X/3*2+Y+2);
		}
		if(!v[3].empty()&&_X>=1){
			int X=_X-1,Y=_Y;
			int Z=min(X,Y);
			X-=Z,Y-=Z;
			res=min(res,Z+X/3*2+Y+1);
		}
		for(auto x:v[0])res+=x/3-1;
		for(auto x:v[1])res+=x/3;
		for(auto x:v[2])res+=x/3;
	}
	printf("%d %d\n",pro,res);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}