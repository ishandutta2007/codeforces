#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,x;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(a<x)a=x;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>x;
		if(b<x)b=x;
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}