#include<bits/stdc++.h>
#pragma GCC optimize("Ofast",3,"inline")
using namespace std;
const int N=1e5+5;
int s[N],pr[N],ne[N];
bool b[N];
long long x;
long long get(){return x=(x*37+10007)%1000000007;}
struct P{
	int a,id;
	inline bool operator<(P x)const{return a>x.a;}
}p[N];
int main(){
	int i,j,k,l,n,d;
	scanf("%d%d%lld",&n,&d,&x);
	for(i=0;i<n;++i)p[i].a=i+1,p[i].id=i;
	for(i=0;i<d;++i)b[i]=1;
	for(i=0;i<n;++i)swap(p[i].a,p[get()%(i+1)].a);
	for(i=0;i<n;++i)swap(b[i],b[get()%(i+1)]);
	if(d>500){
		for(i=0;i<n;++i)pr[i]=i-1,ne[i]=i+1;
		ne[-1]=0,pr[n]=n-1,sort(p,p+n);
		for(i=0;i<n&&!b[i];++i)ne[pr[i]]=ne[i],pr[ne[i]]=pr[i];
		for(l=i,i=0;i<n;++i){
			if(k=p[i].id,k<n-l)for(j=pr[n];j>=k;j=pr[j]){
				if(b[j-k])s[j]=p[i].a,ne[pr[j]]=ne[j],pr[ne[j]]=pr[j];
			}
		}
	}else{
		for(i=0;i<n;++i)if(b[i]){
			for(j=i;j<n;++j)s[j]=max(s[j],p[j-i].a);
		}
	}
	for(i=0;i<n;++i)printf("%d\n",s[i]);
	return 0;
}