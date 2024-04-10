#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans=1e9,cnt; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],ans=min(ans,a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]==ans){
			if(!cnt)cnt=i;
			else cout<<"Still Rozdil",exit(0);
		}
	cout<<cnt<<endl;
	return 0;
}