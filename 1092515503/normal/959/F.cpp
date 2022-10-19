#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,a[100100],d[30],res[100100],tot,pov[100100];
bool ins(int x){
	for(int i=22;i>=0;i--){
		if(!(x&(1<<i)))continue;
		if(d[i])x^=d[i];
		else{d[i]=x;return true;}
	}
	return false;
}
bool find(int x){
	for(int i=22;i>=0;i--){
		if(!(x&(1<<i)))continue;
		if(d[i])x^=d[i];
		else return false;
	}
	return true;
}
vector<pair<int,int> >v[100100];
int main(){
	scanf("%d%d",&n,&m),pov[0]=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pov[i]=(pov[i-1]<<1)%mod;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(make_pair(y,i));
	for(int i=1;i<=n;i++){
		tot+=ins(a[i]);
		for(auto j:v[i])res[j.second]=pov[i-tot]*find(j.first);
	}
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
	return 0;
}