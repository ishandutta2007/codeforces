#include<bits/stdc++.h>
using namespace std;
int a[10009];
int main(){
	int n,i,j=1,u,v;
	cin>>n;
	for(i=2;i<=n;++i){
		cout<<"? "<<j<<' '<<i<<endl;
		cin>>u;
		cout<<"? "<<i<<' '<<j<<endl;
		cin>>v;
		if(u<v)a[i]=v;
		else a[j]=u,j=i;
	}
	a[j]=n;
	cout<<"! ";
	for(i=1;i<=n;++i)cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}