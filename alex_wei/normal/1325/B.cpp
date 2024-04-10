#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,a[N],t;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		cout<<(unique(a+1,a+n+1)-a-1)<<endl;
	}
	return 0;
}