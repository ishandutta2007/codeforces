#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,ans[N],h[N]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	int pre=0;
	for(int i=n;i;i--)ans[i]=max(0,pre+1-h[i]),pre=max(pre,h[i]);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}