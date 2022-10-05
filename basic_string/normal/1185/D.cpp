#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N],b[N];
map<int,int>mp;
void del(int x){
	--mp[x];
	if(mp[x]==0)mp.erase(x);
}
void add(int x){
	++mp[x];
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i),b[i]=a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<n;++i)mp[a[i+1]-a[i]]++;
	for(i=1;i<=n;++i){
		j=lower_bound(a+1,a+n+1,b[i])-a;
		if(j==1){
			del(a[j+1]-a[j]);
		}else if(j==n){
			del(a[j]-a[j-1]);
		}else{
			del(a[j+1]-a[j]);del(a[j]-a[j-1]);add(a[j+1]-a[j-1]);
		}
		if(mp.size()<=1)cout<<i,exit(0);
		if(j==1){
			add(a[j+1]-a[j]);
		}else if(j==n){
			add(a[j]-a[j-1]);
		}else{
			add(a[j+1]-a[j]);add(a[j]-a[j-1]);del(a[j+1]-a[j-1]);
		}
	}cout<<-1;
	return 0;
}