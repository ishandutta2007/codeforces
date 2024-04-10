#include<bits/stdc++.h>
using namespace std;
int n,m,a[200003],dat[1048576];
int query(int a,int b,int l,int r,int k){
	if(a<=l&&r<=b)return dat[k];
	if(a>r||b<l)return 0;
	return query(a,b,l,(l+r)/2,k*2)+query(a,b,(l+r)/2+1,r,k*2+1);
}
void add(int x,int y){while(x)dat[x]+=y,x/=2;}
long long work(){
	for(int i=0;i<1048576;i++)dat[i]=0;add(786431,1);
	long long nw=262143,ret=0;
	for(int i=0;i<n;i++){
		if(a[i]>m)nw--;else nw++;
		ret+=query(0,nw,0,524287,1);
		add(nw+524288,1);
	}
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	long long ans=work();
	m--;ans-=work();cout<<ans;
}