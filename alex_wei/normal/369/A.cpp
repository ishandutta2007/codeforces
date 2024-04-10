#include<bits/stdc++.h>
using namespace std;
//
#define ll long long
int n,m,k,a,ans; 
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==1)m?m--:ans++;
		else k?k--:(m?m--:ans++);
	}
	cout<<ans;
	return 0;
}