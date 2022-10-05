#include<bits/stdc++.h>
using namespace std;
const int N=2099;
int p[N];
int get(int x,int y){
	int w;
	return cout<<"? "<<x<<' '<<y<<endl,cin>>w,w;
}
int main(){
	srand(1437);
	int n,u,v,w,o,i;
	cin>>n;
	for(i=1;i<=n;++i)p[i]=i;
	random_shuffle(p+1,p+n+1),u=p[1],v=p[2],w=get(u,v);
	for(i=3;i<=n;++i){
		o=get(u,p[i]);
		if(o<w)w=o,v=p[i];
		else if(o==w)u=p[i],w=get(u,v);
	}
	for(i=1;i<=n;++i)if(u!=p[i]&&v!=p[i]){
		w=get(u,p[i]),o=get(v,p[i]);
		if(w>o)swap(u,v);
		if(w!=o)break;
	}
	for(i=1;i<=n;++i)if(i!=u)p[i]=get(i,u);else p[i]=0;
	cout<<"! ";
	for(i=1;i<=n;++i)cout<<p[i]<<' ';
	cout<<endl;
	return 0;
}