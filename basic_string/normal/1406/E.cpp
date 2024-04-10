#include<bits/stdc++.h>
using namespace std;
int A(int x){
	int s;
	return cout<<"A "<<x<<endl,cin>>s,s;
}
int B(int x){
	int s;
	return cout<<"B "<<x<<endl,cin>>s,s;
}
const int N=1e5+3;
bool b[N];
int p[9999];
int main(){
	int n,i,j,k,t=0,s=1;
	cin>>n;
	for(i=2;i<=n;++i)if(!b[i]){
		if(i>330)p[++t]=i;
		for(j=i*2;j<=n;j+=i)b[j]=1;
	}
	for(i=2;i<=min(n,330);++i)if(!b[i]){
		B(i);
		for(j=1;j*i<=n&&A(j*i);j*=i);
		s*=j;
	}
	if(s>1){for(i=t;i;--i)if(A(p[i])>1){
		s*=p[i];
		goto gg;
	}}else for(i=t;i>0;i-=100){
		j=max(1,i-99);
		for(k=j;k<=i;++k)B(p[k]);
		if(A(1)>j)for(k=j;k<=i;++k)if(A(p[k])){
			s*=p[k];
			goto gg;
		}
	}
	gg:cout<<"C "<<s<<endl;
	return 0;
}