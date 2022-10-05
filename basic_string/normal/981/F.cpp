#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
unsigned a[N*2],b[N*4];
int n,o;
bool chk(int x){
	int mn=1e9,l=1,r=0,i;
	for(i=1;i<=n*2;++i){
		while(b[l]<a[i]-x)++l;
		while(b[r+1]<=a[i]+x)++r;
		mn=min(mn,i-l);
		if(i-r>mn)return 0;
	}
	return 1;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,l=0,r,m;
	cin>>n>>o,r=o/2;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=n;++i)cin>>b[i];
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for(i=1;i<=n;++i)a[i]+=o,a[i+n]=a[i]+o,b[i+n]=b[i]+o,b[i+n+n]=b[i+n]+o,b[i+n*3]=b[i+n+n]+o;
	while(l<=r){
		m=l+r>>1;
		if(chk(m))r=m-1;else l=m+1;
	}
	cout<<l;
}