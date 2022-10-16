#include<bits/stdc++.h>
const int N=4e5;
int n,a[N],L[N],A,V[N*2],h,t,d[N];
void c(int p,int v){V[d[p]+a[d[p+1]]]+=v;}
int main(){
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
		while(h<t&&d[h]<L[a[i]])d[h+1]<=L[a[i]]?c(h++,-1):(c(h,-1),d[h]=L[a[i]],c(h,1));
		while(h<t&&a[d[t]]<a[i])c(--t,-1);
		d[++t]=L[a[i]]=i,c(t-1,1),A+=V[i];
	}
	std::cout<<A<<"\n";
}