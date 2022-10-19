#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100],b[200100],mode,s[200100],c[200100],res,cnt;
void ADJ(int x,int tp){
	if(x!=mode)c[b[x]]--;
	b[x]+=tp;
	if(x!=mode)c[b[x]]++;
	if(c[cnt+1])cnt++;
	if(!c[cnt])cnt--;
}
void read(int&x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar(); 
}
int main(){
	read(n),m=sqrt(n);
	for(int i=1;i<=n;i++)read(a[i]),b[a[i]]++;
	for(int i=1;i<=n;i++)if(b[i]>b[mode])mode=i;
	for(int i=1;i<=n;i++)if(b[i]>=m&&i!=mode){
		int mn=0;
		for(int j=1;j<=n;j++){
			s[j]=s[j-1];
			if(a[j]==i)s[j]++;
			if(a[j]==mode)s[j]--;
			mn=min(mn,s[j]);
		}
		for(int j=0;j<=n;j++)s[j]-=mn;
		for(int j=n;j>=0;j--)c[s[j]]=j;
		for(int j=0;j<=n;j++)res=max(res,j-c[s[j]]);
	}
	for(int i=1;i<=m;i++){
		memset(b,0,sizeof(b)),memset(c,0,sizeof(c)),c[0]=n,cnt=0;
		for(int r=1,l=1;r<=n;r++){
			ADJ(a[r],1);
			if(b[mode]<i)continue;
			while(b[mode]>i||cnt>i)ADJ(a[l++],-1);
			if(cnt!=i)continue;
			res=max(res,r-l+1);
		}
	}
	printf("%d\n",res);
	return 0;
}