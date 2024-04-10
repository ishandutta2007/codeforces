#include<bits/stdc++.h>
using namespace std;
enum{N=129};
int a[N][3],k[N],c,h;
bool v[N];
void get(int x){
	if(v[x])return;
	if(v[x]=1,++c,c>16)throw x;
	cout<<"? "<<x<<'\n',cin>>k[x];
	for(int i=0;i<k[x];++i)cin>>a[x][i];
	if(k[x]==2)throw x;
}
int dfs(int x,int y,int o){
	if(o>2)return 0;
	if(get(x),k[x]==1)return h;
	for(int i=0;i<3;++i)if(a[x][i]!=y)return dfs(a[x][i],x,o+1)-1;
}
void wk(int x,int y,int d){
	int i,j;
	if(d<4){
		queue<int>q;
		for(q.push(x);;)for(i=q.front(),q.pop(),get(i),j=0;j<k[i];++j)q.push(a[i][j]);
	}
	if(get(x),k[x]==1)wk(a[x][0],x,h-1);
	if(d<N)for(i=0;i<3;++i)if(a[x][i]!=y){
		if(dfs(a[x][i],x,0)<d)wk(a[x][i],x,d-1);else{
			for(++i;i<3;++i)if(a[x][i]!=y)wk(a[x][i],x,d-1);
		}
	}
	if(i=dfs(a[x][0],x,0),j=dfs(a[x][1],x,0),i<0)j<0?wk(x,0,3):wk(a[x][0],x,j-2);
	if(i<j)wk(a[x][0],x,j-2);else if(i>j)wk(a[x][1],x,i-2);else wk(a[x][2],x,i-2);
}
int main(){
	int T;
	for(cin>>T;T--;){
		memset(v,0,N),cin>>h,c=0;
		try{wk(1,0,N);}catch(int x){cout<<"! "<<x<<'\n';}
	}
	return 0;
}