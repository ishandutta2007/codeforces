#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int main(){
	cin>>t;
	while(t--){
		int a[105],n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)cout<<a[n-i+1]<<" ";
		puts("");
	}
	return 0;
}