#include<bits/stdc++.h>
using namespace std;
int T,n,a[100100],b[100100];
vector<int>u,v;
bool che(int ip){
	for(int i=1;i<=n;i++)u.push_back(a[i]);
	for(int i=1;i<=n;i++)v.push_back(b[i]);
	while(u.size()<ip)u.push_back(100);
	while(v.size()<ip)v.push_back(0);
	sort(u.rbegin(),u.rend()),u.resize(ip-ip/4);
	sort(v.rbegin(),v.rend()),v.resize(ip-ip/4);
	int U=0,V=0;
	for(auto x:u)U+=x;
	for(auto x:v)V+=x;
	u.clear(),v.clear();
	return U>=V;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		int l=n,r=2*n;
		while(l<r){
			int mid=(l+r)>>1;
			if(che(mid))r=mid;
			else l=mid+1;
		}
		printf("%d\n",r-n);
	}
	return 0;
}