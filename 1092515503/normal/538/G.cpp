#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll T[200100],X[200100],Y[200100];
struct dat{
	ll k,w,z;
	dat(ll K,ll W,ll Z){k=K,w=W,z=Z;}
	friend bool operator<(const dat&u,const dat&v){return u.w<v.w;}
};
vector<dat>v[2];
int s[2][2001000];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&T[i],&X[i],&Y[i]);
		if((T[i]+X[i]+Y[i])&1){puts("NO");return 0;}
		v[0].emplace_back(T[i]/m,T[i]%m,(T[i]+X[i]+Y[i])/2);
		v[1].emplace_back(T[i]/m,T[i]%m,(T[i]+Y[i]-X[i])/2);
	}
	memset(s,-1,sizeof(s));
	for(int t=0;t<2;t++){
//		printf("%d:\n",t);
		v[t].emplace_back(0,0,0),v[t].emplace_back(-1,m,0);
		sort(v[t].begin(),v[t].end());
//		for(auto x:v[t])printf("[%lld,%lld,%lld]",x.k,x.w,x.z);puts("");
		ll mn=0,mx=m;
		for(int i=1;i<v[t].size();i++){
			ll K=v[t][i].k-v[t][i-1].k,W=v[t][i].w-v[t][i-1].w,Z=v[t][i].z-v[t][i-1].z;
			ll L=Z-W,R=Z;
			if(!K){if(L>0||R<0){puts("NO");return 0;}continue;}
			if(K<0)swap(L,R),L=-L,R=-R,K=-K;
			L=max(L,mn*K),R=min(R,mx*K);
			if(L)mn=max(mn,(L-1)/K+1);
			mx=min(mx,R/K);
		}
		if(mn>mx){puts("NO");return 0;}
		s[t][0]=0,s[t][m]=mn;
		for(int i=0;i+1<v[t].size();i++)s[t][v[t][i].w]=v[t][i].z-mn*v[t][i].k;
		for(int l=0,r;;){
			while(l<=m&&s[t][l]!=-1)l++;
			if(l>m)break;
			r=l;while(r<=m&&s[t][r]==-1)r++;
			while(l<r)s[t][l]=min(s[t][r],s[t][l-1]+1),l++;
		}
	}
	for(int i=1;i<=m;i++){
		int x=s[0][i]-s[0][i-1],y=s[1][i]-s[1][i-1];
		if(x==0&&y==0)putchar('D');
		if(x==1&&y==1)putchar('U');
		if(x==1&&y==0)putchar('R');
		if(x==0&&y==1)putchar('L');
	}
	return 0;
}