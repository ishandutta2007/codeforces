#include<bits/stdc++.h>
using namespace std;
const int N=10000;
typedef long long ll;
typedef __int128 ii;
const ii LIM=1e36;
const ll lim=1e18;
const int mil=1e9;
int pri[10100],T;
void sieve(){
	for(int i=2;i<=N;i++){
		if(!pri[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			pri[i*pri[j]]=true;
			if(!(i%pri[j]))break;
		}
	}
}
ll ksm(int x,int y){ll z=1;while(y--)z*=x;return z;}
int main(){
	sieve();
	scanf("%d",&T);
	while(T--){
		vector<int>v,u;
		for(int l=1,r=1;;l=r){
			if(1ll*pri[l]*pri[l+1]*pri[l+2]*pri[l+3]>mil)break;
			ll prod=1;
			while((ii)prod*pri[r]<=lim)prod*=pri[r++];
			printf("? %lld\n",prod),fflush(stdout);
			scanf("%lld",&prod);
			for(int k=l;k<r;k++)if(!(prod%pri[k]))v.push_back(k);
		}
		if(v.empty()){puts("! 8"),fflush(stdout);continue;}
		if(v.size()>8){puts("! 1024"),fflush(stdout);continue;}
		int num=mil;
		for(auto x:v)num/=pri[x];
		u.resize(v.size());
		for(int l=0,r=0;l<v.size();l=r){
			ll prod=1;
			while(r<v.size()){
				int val=1;
				while(val<=num)val*=pri[v[r]];
				if(val==pri[v[r]]){u[r++]=1;continue;}
				if((ii)prod*val>lim)break;
				prod*=val,r++;			
			}
			printf("? %lld\n",prod),fflush(stdout);
			scanf("%lld",&prod);
			for(int k=l;k<r;k++)while(!(prod%pri[v[k]]))u[k]++,prod/=pri[v[k]];
		}
		int sum=1;num=1;
		for(int i=0;i<v.size();i++)num*=(1+u[i]),sum*=ksm(pri[v[i]],u[i]);
		if(num*8<=2*num+14){printf("! %d\n",num+7),fflush(stdout);continue;}
		v.clear(),u.clear();
		for(int l=41,r=41;;l=r){
			if(1ll*sum*pri[l]*pri[l+1]*pri[l+2]>mil)break;
			ll prod=1;
			while((ii)prod*pri[r]<=lim)prod*=pri[r++];
			printf("? %lld\n",prod),fflush(stdout);
			scanf("%lld",&prod);
			for(int k=l;k<r;k++)if(!(prod%pri[k]))v.push_back(k);
		}
		int mun=mil/sum;
		for(auto x:v)mun/=pri[x];
		u.resize(v.size());
		for(int l=0,r=0;l<v.size();l=r){
			ll prod=1;
			while(r<v.size()){
				int val=1;
				while(val<=mun)val*=pri[v[r]];
				if(val==pri[v[r]]){u[r++]=1;continue;}
				if((ii)prod*val>lim)break;
				prod*=val,r++;
			}
			if(prod==1)continue;
			printf("? %lld\n",prod),fflush(stdout);
			scanf("%lld",&prod);
			for(int k=l;k<r;k++)while(!(prod%pri[v[k]]))u[k]++,prod/=pri[v[k]];
		}
		for(int i=0;i<v.size();i++)num*=(1+u[i]),sum*=ksm(pri[v[i]],u[i]);
		printf("! %d\n",2*num);fflush(stdout);
	}
	return 0;
}