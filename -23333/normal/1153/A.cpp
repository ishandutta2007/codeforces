#include<bits/stdc++.h>
using  namespace std;
int n,t;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t;
	int az=0;long long maxer=1000000000;
	for(int i=1;i<=n;i++){
	int a,b;
	cin>>a>>b;
	for(int j=0;j<=t;j++)
		if(j*b+a>=t){
		if(j*b+a-t<maxer){maxer=j*b+a-t;az=i;}
		break;
		}
	}
	cout<<az;
	return 0;
}