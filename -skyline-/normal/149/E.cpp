#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
int n,a[110005],z[110005],L[100005],R[100005];
int b[100005],B,d[1005],D,q,ans;
void upd(int &x,int y){if(y>x)x=y;}
void getz(){
	int l=1,r=1;
	for(int i=2;i<=n;++i){
		if(i>r){
			l=i,r=i;
			while(r<=n&&a[r]==a[r-i+1])++r;
			z[i]=r-l,--r;
		}
		else{
			int k=i-l+1;
			if(z[k]<r-i+1)z[i]=z[k];
			else{
				l=i;
				while(r<=n&&a[r]==a[r-i+1])++r;
				z[i]=r-l,--r;
			}
		}
	}
}
int main(){
	char c=getchar();
	while(c!='\n')b[++B]=c,c=getchar();
	scanf("%d",&q);
	while(q--){
		c=getchar();
		if(c=='\n')c=getchar();
		D=0;
		while(c!='\n')d[++D]=c,c=getchar();
		if(D==1) continue;
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		n=0;
		for(int i=1;i<=D;++i)a[++n]=d[i];
		for(int i=1;i<=B;++i)a[++n]=b[i];
		getz();
		for(int i=D+1;i<=n;++i)upd(L[z[i]+i-D-1],z[i]);
		for(int i=2;i<=B;++i)upd(L[i],L[i-1]);
		n=0;
		for(int i=D;i;--i)a[++n]=d[i];
		for(int i=B;i;--i)a[++n]=b[i];
		getz();
		for(int i=n;i>D;--i)upd(R[n+2-i-z[i]],z[i]);
		for(int i=B-1;i;--i)upd(R[i],R[i+1]);
		bool ok=0;
		for(int i=1;i<=B;++i)if(L[i]+R[i+1]>=D)ok=1,i=B;
		if(ok)++ans;
	}
	printf("%d\n",ans);
	return 0;
}