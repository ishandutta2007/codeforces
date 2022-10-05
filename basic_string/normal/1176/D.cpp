#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5;
int a[N],p[N],q[N];
bool f[N];
map<int,int,greater<int> >mp;
int main(){
	int n,m,t=0,o=0,i,j,k;
	scanf("%d",&n),m=n*2;
	for(i=1;i<=m;++i)scanf("%d",&j),++mp[j];
	for(f[1]=1,i=2;i<N;++i){
		if(!f[i])p[++t]=i,q[i]=t;
		for(j=1;j<=t&&(k=i*p[j])<N;++j){
			f[k]=1,q[k]=i;
			if(!(i%p[j]))break;
		}
	}
	for(auto w:mp){
		while(w.second){
			--w.second,--mp[q[w.first]];
			if(f[w.first])a[++o]=w.first;
			else a[++o]=q[w.first];
		}
	}
	for(i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}