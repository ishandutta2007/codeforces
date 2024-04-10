#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
int n,k,a[N],s; 
int main(){
	cin>>n>>k; 
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		puts("0");
		cout<<a[1];
		exit(0); 
	}
	while(a[1]+a[2]<k)s++,a[2]++;
	for(int i=2;i<n;i++)while(a[i]+a[i+1]<k)s++,a[i+1]++;
	cout<<s<<endl;
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}