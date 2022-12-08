#include<bits/stdc++.h>

#define LL long long 

using namespace std;

const int N=2e5*30;
LL dep[N],x,n,sz,l[N],r[N],ans;

int F(int u,int v,int d){
	if(!d)return 0;
	int s=1<<d;
	if(l[u]&&l[v])s=F(l[u],l[v],d-1);
	if(r[u]&&r[v])s=min(s,F(r[u],r[v],d-1));
	if(s<1<<d)return s;
	if(l[u]&&r[v])
		return F(l[u],r[v],d-1)|1<<d-1;
	if(r[u]&&l[v])
		return F(r[u],l[v],d-1)|1<<d-1;
}
int main(){
	cin>>n;
	dep[0]=30;
	for(int i=0;i<n;i++){
		cin>>x;
		for(int j=0,d=29;~d;d--){
			LL &s=(x>>d&1?r:l)[j];
			if(!s)
				dep[s=++sz]=d;
			j=s;
		}
	}
	for(int i=0;i<=sz;i++)
		if(l[i]&&r[i])
			ans+=(1<<dep[i]-1)+F(l[i],r[i],dep[i]-1);
	cout<<ans<<endl;
}