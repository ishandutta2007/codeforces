#include<bits/stdc++.h>
using namespace std;
bool f[1009];
int main(){
	int n,k,s,w=0,i,j;
	cin>>n,k=sqrt(n),s=n-k-(n-1)/k;
	while(w<s){
		cout<<k<<' ',j=0;
		for(i=1;j<k;++i)if(!f[i]&&i%k)cout<<i<<' ',f[i]=1,++w,++j;
		cout<<endl,cin>>j;
		for(i=0;i<k;++i,j=j%n+1)if(f[j])--w,f[j]=0;
	}
	cout<<0<<endl;
	return 0;
}