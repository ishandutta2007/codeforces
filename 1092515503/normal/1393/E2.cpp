#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,S[100100],f[1001000],g[1001000],sum[100100],res;
char *s[100100],ss[1001000];
vector<int>v[1001000];
int md=666623333;
int pov[1000100];
struct HASH{
	int val;int len;
	HASH(){val=0;len=0;}
	HASH(char ip){val=ip-'a';len=1;}
	friend HASH operator+(const HASH&x,const HASH&y){
		HASH z;z.val=(1ll*x.val*pov[y.len]+y.val)%md;
		z.len=x.len+y.len;return z;
	}
	friend HASH operator-(const HASH&x,const HASH&y){
		HASH z;
		z.val=(x.val-1ll*y.val*pov[x.len-y.len]%md+md)%md;
		z.len=x.len-y.len;return z;
	}
	friend bool operator==(const HASH&x,const HASH&y){return x.len==y.len&&x.val==y.val;}
	friend bool operator!=(const HASH&x,const HASH&y){return!(x==y);}
}hs[1000100];
HASH HS(int l,int r){if(r+1<l)return HASH();return hs[r+1]-hs[l];}
bool cmp(int i,int j,int k){
//	printf("%d(%d,%d),%d,%d\n",i,sum[i],sum[i+1],j,k);
	int len=min(j,k);
	if(HS(sum[i],sum[i]+len-1)!=HS(sum[i+1],sum[i+1]+len-1)){
		int l=0,r=len-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(HS(sum[i],sum[i]+mid-1)!=HS(sum[i+1],sum[i+1]+mid-1))r=mid-1;
			else l=mid;
		}
		return ss[sum[i]+l]<ss[sum[i+1]+l];
	}
//	puts("DUDUDU");
	int nel=min(max(j,k),min(S[i]-(len>=j),S[i+1]-(len>=k)));
	int U=sum[i]+(len>=j),V=sum[i+1]+(len>=k);
	if(HS(U+len,U+nel-1)!=HS(V+len,V+nel-1)){
		int l=0,r=nel-len-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(HS(U+len,U+len+mid-1)!=HS(V+len,V+len+mid-1))r=mid-1;
			else l=mid;
		}
		return ss[U+len+l]<ss[V+len+l];
	}
	if(nel<max(j,k))return S[i]-(j!=S[i])<=S[i+1]-(k!=S[i+1]);
//	puts("HUHUHU");
	int l=nel+1,r=min(S[i]-1,S[i+1]-1);
	if(HS(sum[i]+l,sum[i]+r)!=HS(sum[i+1]+l,sum[i+1]+r)){
		while(l<r){
			int mid=(l+r+1)>>1;
			if(HS(sum[i]+nel+1,sum[i]+mid-1)!=HS(sum[i+1]+nel+1,sum[i+1]+mid-1))r=mid-1;
			else l=mid;
		}
		return ss[sum[i]+l]<ss[sum[i+1]+l];
	}
//	puts("GUGUGU");
	return S[i]-(j!=S[i])<=S[i+1]-(k!=S[i+1]);
}
int main(){
	scanf("%d",&n);
	s[0]=ss;for(int i=0;i<n;i++)
		scanf("%s",s[i]),S[i]=strlen(s[i]),s[i+1]=s[i]+S[i],sum[i+1]=sum[i]+S[i];
	pov[0]=1;for(int j=1;j<=sum[n];j++)pov[j]=31ll*pov[j-1]%md;
//	printf("GUGUGU:%d\n",sum[n]);
	for(int i=0;i<sum[n];i++)hs[i+1]=hs[i]+ss[i];
	for(int i=0;i<n;i++){
		v[i].resize(S[i]+1);
		int l=0,r=v[i].size()-1,las=0;
		for(int j=0;j+1<S[i];j++){
			if(s[i][j]==s[i][j+1])continue;
			if(s[i][j]>s[i][j+1])for(int t=las;t<=j;t++)v[i][l++]=j;
			else for(int t=j;t>=las;t--)v[i][r--]=j;
			las=j+1;
		}
		for(int j=las;j<=S[i];j++)v[i][l++]=j;
//		for(auto x:v[i])printf("%d ",x);puts("");
	}
	for(int i=0;i<v[0].size();i++)f[i]=1;
	for(int i=0;i+1<n;i++){
//		printf("%d\n",i);
		for(int j=0,k=0;j<v[i].size();j++){
			while(k<v[i+1].size()&&!cmp(i,v[i][j],v[i+1][k]))k++;
//			printf("<%d,%d>:%d\n",j,k,f[j]);
			if(k==v[i+1].size())break;
			(g[k]+=f[j])%=mod,f[j]=0;
		}
		for(int j=0;j<v[i+1].size();j++)f[j]=g[j],g[j]=0;
		for(int j=1;j<v[i+1].size();j++)(f[j]+=f[j-1])%=mod;
//		for(int i=0;i<v[i+1].size();i++)printf("%d ",f[i]);puts("");
	}
	for(int i=0;i<v[n-1].size();i++)(res+=f[i])%=mod;
	printf("%d\n",res);
	return 0;
}