#include<bits/stdc++.h>
using namespace std;
int T,n,lim,m,a[100100],f[100100];
vector<int>v;
int main(){
	scanf("%d%d%d%d",&T,&n,&lim,&m);
	while(T--){
		v.clear();
		for(int i=0;i<n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
		sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin());
		if(v.size()<=m){printf("%d\n",v.size());continue;}
		for(int i=0;i<n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
		for(int i=1;i<=v.size();i++)f[i]=0;
		for(int i=0;i<n*m;i++){
			int now=f[a[i%n]-1]+1;
			for(int j=a[i%n];j<=v.size();j++)if(f[j]<now)f[j]=now;else break;
			if(f[v.size()]==v.size())break;
		}
		printf("%d\n",f[v.size()]);
	}
	return 0;
}
/*
5 10 10 1
1 2 2 4 3 2 6 3 5 2
3 2 4 3 2 1 6 3 2 3
6 3 3 2 2 1 1 2 1 1
9 8 7 6 5 4 3 3 2 1
2 3 4 1 5 6 7 4 3 2
*/