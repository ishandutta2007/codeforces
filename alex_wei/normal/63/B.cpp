#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105+5;
int n,k,a[N],ans; 
bool check(){
	for(int i=1;i<=n;i++)if(a[i]!=k)return false;
	return true;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[n+1]=k+1;
	while(!check()){
		for(int i=2;i<=n+1;i++)if(a[i]!=a[i-1]&&a[i-1]<k)a[i-1]++;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}