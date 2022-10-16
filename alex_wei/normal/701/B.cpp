#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n,m,x,y,r,c,a[N],b[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		if(!a[x])r++,a[x]=1;
		if(!b[y])c++,b[y]=1;
		printf("%lld ",(n-r)*(n-c));
	}
    return 0;
}