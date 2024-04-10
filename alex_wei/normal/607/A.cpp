#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

struct node{
	int a,b;
	bool operator < (const node &v) const {
		return a<v.a;
	}
}c[N];

int n,f[N],ans;

int main(){
	cin>>n,c[0].a=-1e9;
	for(int i=1;i<=n;i++)cin>>c[i].a>>c[i].b;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		int l=0,r=i-1,p=c[i].a-c[i].b;
		while(l<r){
			int m=(l+r>>1)+1;
			if(p<=c[m].a)r=m-1;
			else l=m;
		} ans=max(ans,f[i]=f[l]+1);
	} cout<<n-ans<<endl;
	return 0;
}