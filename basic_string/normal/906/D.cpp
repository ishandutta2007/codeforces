#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int w[N];
unordered_map<int,int>ph;
int phi(int x){
	int i,s=x;
	for(i=2;i*i<=x;++i)if(x%i==0)for(s=s/i*(i-1),x/=i;x%i==0;x/=i);
	return x>1?s/x*(x-1):s;
}
pair<int,bool>cal(int x,int e,int p){
	if(x>e)return{1,0};
	if(p==1)return{0,1};
	if(!ph.count(p))ph[p]=phi(p);
	auto o=cal(x+1,e,ph[p]);
	long long a=w[x],b=o.first+0ll+o.second*ph[p],r=1;
	bool f=0;
	if(a>=p)a%=p,f=1;
	for(;b;){
		if(b&1)if((r*=a)>=p)r%=p,f=1;
		if(b>>=1)if((a*=a)>=p)a%=p,f=1;
	}
	return{r,f};
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,p,i,j;
	for(i=1,cin>>n>>p;i<=n;++i)cin>>w[i];
	for(cin>>m;m--;)cin>>i>>j,cout<<cal(i,j,p).first<<'\n';
	return 0;
}