#include<bits/stdc++.h>
using namespace std;
int a[33];
int main(){
	int T,d,m,i,n,ans;
	cin>>T;
	while(T--){
		cin>>d>>m,ans=1;
		for(i=0;;++i){
			if((1<<i+1)<=d)a[i]=(1<<i+1)-(1<<i);
			else{
				a[i]=d-(1<<i)+1,n=i;
				break;
			}
		}
		for(i=0;i<=n;++i)ans=ans*1ll*(a[i]+1)%m;
		cout<<((ans-1)%m+m)%m<<'\n';
	}
	return 0;
}