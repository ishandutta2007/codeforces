#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t[200000];
ll num,c,n,a;
int main(){
	cin>>c>>n;
	t[0]=1;
	for(int i=1;i<=n;i++)
	t[i]=t[i-1]*c%2;
	for(int i=1;i<=n;i++){
	cin>>a;
	num=(num+a*t[n-i])%2;
	}
	if(num)cout<<"odd";else cout<<"even";
	return 0;	
}