#include<bits/stdc++.h>
using namespace std;
enum{N=250009};
int a[N];
int u,v;
int mn(int x,int y){return a[x]<a[y]?x:y;}
int mx(int x,int y){return a[x]>a[y]?x:y;}
int n;
namespace A{
	int st[N][20];
	int qry(int l,int r){
		int i=__lg(r-l+1);
		return mn(st[l][i],st[r-(1<<i)+1][i]);
	}
	void in(){
		int i,j,k;
		for(i=1;i<=n;++i)st[i][0]=i;
		for(i=n;i;--i){
			for(j=0;i+(1<<(j+1))-1<=n;++j){
				st[i][j+1]=mn(st[i][j],st[i+(1<<j)][j]);
			}
		}
	}
}
namespace B{
	int st[N][20];
	int qry(int l,int r){
		int i=__lg(r-l+1);
		return mx(st[l][i],st[r-(1<<i)+1][i]);
	}
	void in(){
		int i,j,k;
		for(i=1;i<=n;++i)st[i][0]=i;
		for(i=n;i;--i){
			for(j=0;i+(1<<(j+1))-1<=n;++j){
				st[i][j+1]=mx(st[i][j],st[i+(1<<j)][j]);
			}
		}
	}
}
#define qra() (A::qry(u,v))
#define qrb() (B::qry(u,v))
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,m,i,j,k,l,r; 
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		A::in(),B::in();
		int ans=0;
		for(i=1,j=1;;){
			if(i==n)break;
			if(j){
				l=i,r=n+1;
				while(l<r){
					m=(l+r)>>1;
					if(u=i,v=m,qra()==i)l=m+1;
					else r=m;
				}
				u=i,v=l-1,i=qrb();
			}else{
				l=i,r=n+1;
				while(l<r){
					m=(l+r)>>1;
					if(u=i,v=m,qrb()==i)l=m+1;
					else r=m;
				}
				u=i,v=l-1,i=qra();
			}++ans;
			j=!j;
		}
		int now=0;
		for(i=1,j=0;;){
			if(i==n)break;
			if(j){
				l=i,r=n+1;
				while(l<r){
					m=(l+r)>>1;
					if(u=i,v=m,qra()==i)l=m+1;
					else r=m;
				}
				u=i,v=l-1,i=qrb();
			}else{
				l=i,r=n+1;
				while(l<r){
					m=(l+r)>>1;
					if(u=i,v=m,qrb()==i)l=m+1;
					else r=m;
				}
				u=i,v=l-1,i=qra();
			}++now;
			j=!j;
		}
		cout<<min(ans,now)<<'\n';
	}
}