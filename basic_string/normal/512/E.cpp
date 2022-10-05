#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>ans,ans2;
enum{N=1009};
int n,a[N];
bool e[N][N];
void wk1(int l,int r){
	if(l+1==r)return;
	int i;
	for(i=l+1;i<r;++i)if(e[i][l]&&e[i][r]){
		ans.push_back({l,r});
		wk1(l,i),wk1(i,r);
		return;
	}
}
void wk2(int l,int r){
	if(l+1==r)return;
	int i;
	for(i=l+1;i<r;++i)if(e[i][l]&&e[i][r]){
		ans.push_back({1,i});
		wk2(l,i),wk2(i,r);
		return;
	}
}
void work1(){
	memset(e,0,sizeof e);
	int i,j,k,t=0;
	for(i=1;i<=n;++i)j=i%n+1,e[i][j]=e[j][i]=1;
	for(i=1;i<=n-3;++i)cin>>j>>k,e[j][k]=e[k][j]=1;
	for(i=2;i<=n;++i)if(e[1][i])a[++t]=i;
	for(i=1;i<t;++i)wk1(a[i],a[i+1]);
}
void work2(){
	memset(e,0,sizeof e);
	int i,j,k,t=0;
	for(i=1;i<=n;++i)j=i%n+1,e[i][j]=e[j][i]=1;
	for(i=1;i<=n-3;++i)cin>>j>>k,e[j][k]=e[k][j]=1;
	for(i=2;i<=n;++i)if(e[1][i])a[++t]=i;
	for(i=1;i<t;++i)wk2(a[i],a[i+1]);
}
int main(){
	cin>>n;
	work1();
	ans2=ans,ans={};
	work2();
	cout<<ans.size()+ans2.size()<<'\n';
	for(auto o:ans2)cout<<o.first<<' '<<o.second<<'\n';
	reverse(begin(ans),end(ans));
	for(auto o:ans)cout<<o.first<<' '<<o.second<<'\n';
	return 0;
}