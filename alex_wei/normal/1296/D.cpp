#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a,b,k,h,d[N],ans; 
int main(){
	cin>>n>>a>>b>>k;
	for(int i=1;i<=n;i++){
		cin>>h;
		int rem=h%(a+b);
		if(rem==0)d[i]=(b-1)/a+1;
		else d[i]=(rem-1)/a;
	}
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++){
		d[i]+=d[i-1];
		if(d[i]>k)cout<<i-1,exit(0);
	}
	cout<<n<<endl;
	return 0;
}