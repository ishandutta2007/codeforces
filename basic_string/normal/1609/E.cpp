#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
struct M{
	int a[3][3];
}s[N*4],w;
char ss[N];
int u,n;
void mul(M&c,M&a,M&b){
	int i,j,k;
	for(i=0;i<3;++i)for(j=0;j<3;++j)c.a[i][j]=N;
	for(i=0;i<3;++i)for(j=0;j<3;++j)
	for(k=0;k<3;++k)c.a[i][k]=min(c.a[i][k],a.a[i][j]+b.a[j][k]); 
}
void upd(int k,int l,int r){
	if(l==r){
		s[k]=w;
		return;
	}
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);
	else upd(k*2+1,m+1,r);
	mul(s[k],s[k*2],s[k*2+1]);
}
void upd(int x){
	u=x;
	for(int i=0;i<3;++i)for(int j=0;j<3;++j){
		if(i>j)w.a[i][j]=N;
		else if(i<j)w.a[i][j]=0;
		else{
			if(i==0)w.a[i][j]=(ss[x]=='a');
			else if(i==1)w.a[i][j]=(ss[x]=='b');
			else w.a[i][j]=(ss[x]=='c');
		}
	}
	upd(1,1,n);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,i;
	char c;
	cin>>n>>q>>ss+1;
	for(i=1;i<=n;++i)upd(i);
	while(q--){
		cin>>i>>c;ss[i]=c;upd(i);
		cout<<min(s[1].a[0][2],min(s[1].a[1][2],s[1].a[2][2]))<<'\n';
	}
	return 0;
}