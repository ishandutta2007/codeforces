#include<bits/stdc++.h>
using namespace std;
enum{N=69,M=259};
int m,id[N][N],x[M],y[M];
struct A{
	bitset<M>u,v;
}a[M],c;
bool b[M];
void del(A&x,const A&y){
	A a;
	a.u=(x.u&(~(y.u|y.v)))|(x.v&y.u)|((~(x.u|x.v))&y.v);
	a.v=(x.v&(~(y.u|y.v)))|((~(x.u|x.v))&y.u)|(x.u&y.v);
	x=a;
}
void add(A&x,const A&y){
	A a;
	a.u=(x.u&(~(y.u|y.v)))|(x.v&y.v)|((~(x.u|x.v))&y.u);
	a.v=(x.v&(~(y.u|y.v)))|((~(x.u|x.v))&y.v)|(x.u&y.u);
	x=a;
}
bool wk(){
	int i,j;
	for(i=1;i<=m;++i)if(b[i]){
		if((a[i].u[i]&&c.u[i])||(a[i].v[i]&&c.v[i]))del(c,a[i]);
		else if((a[i].u[i]&&c.v[i])||(a[i].v[i]&&c.u[i]))add(c,a[i]);
	}
	for(i=1;i<=m;++i)if(c.u[i]||c.v[i]){
		b[i]=1,a[i]=c;
		for(j=1;j<=m;++j)if(i!=j&&b[j]){
			if((a[j].u[i]&&c.u[i])||(a[j].v[i]&&c.v[i]))del(a[j],c);
			else if((a[j].u[i]&&c.v[i])||(a[j].v[i]&&c.u[i]))add(a[j],c);
		}
		return 1;
	}
	if(c.u[0]||c.v[0])return 0;
	return 1;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,l;
	for(cin>>T;T--;){
		cin>>n>>m;
		memset(id,0,sizeof id);memset(b,0,sizeof b);
		for(i=1;i<=m;++i){
			cin>>j>>k>>l;
			x[i]=j,y[i]=k;
			id[j][k]=id[k][j]=i;
			if(l>0){
				c.u.reset(),c.v.reset();
				c.u[i]=1;
				if(l==1)c.u[0]=1;else if(l==2)c.v[0]=1;
				wk();
			}
		}
		for(i=1;i<=m;++i){
			for(j=1;j<=n;++j)if(id[x[i]][j]&&id[y[i]][j]){
				c.u.reset(),c.v.reset();
				c.u[i]=c.u[id[x[i]][j]]=c.u[id[y[i]][j]]=1;
				if(!wk()){cout<<"-1\n";goto gg;}
			}
		}
		for(i=1;i<=m;++i)if(b[i]){
			if(a[i].u[0])cout<<(a[i].u[i]?1:2)<<' ';
			else if(a[i].v[0])cout<<(a[i].v[i]?1:2)<<' ';
			else cout<<"3 ";
		}else cout<<"3 ";
		cout<<'\n';
		gg:;
	}
}