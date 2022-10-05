#include<bits/stdc++.h>
using namespace std;
#define ll long long
int p[10003];
ll a[10003]; 
int main(){
	int n,s,i;
	ll w,c,o=0;
	cin>>n>>c;
	for(i=0;i<n;++i)cin>>p[i],o+=p[i];
	for(i=0;i<n;++i)cin>>s,a[i]=c*(n-i-1)+s-p[i];
	w=o,sort(a,a+n);
	for(i=0;i<n;++i)w=min(w,o+=a[i]-c*i);
	cout<<w;
	return 0;
}