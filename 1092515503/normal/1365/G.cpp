#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,num[1010],id;
ll val[13];
vector<int>v[13];
int main(){
	scanf("%d",&n);
	for(int i=0;i<(1<<13);i++){
		if(__builtin_popcount(i)!=6)continue;
		num[++id]=i;
		for(int j=0;j<13;j++)if(!(i&(1<<j)))v[j].push_back(id);
		if(id==n)break;
	}
	for(int i=0;i<13;i++){
		if(v[i].empty())continue;
		printf("? %d",v[i].size());
		for(auto x:v[i])printf(" %d",x);puts(""),fflush(stdout);
		scanf("%lld",&val[i]);
	}
	putchar('!');
	for(int i=1;i<=n;i++){
		ll res=0;
		for(int j=0;j<13;j++)if(num[i]&(1<<j))res|=val[j];
		printf(" %lld",res);
	}
	puts(""),fflush(stdout);
	return 0;
}