#include<bits/stdc++.h>
using namespace std;
int n,m,pd[1002],k,ans;
string s; 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>s>>s>>s;
		if(s[0]=='l'){
			cin>>s>>k;
			for(int i=k;i<=n;i++)
				pd[i]=1;
		}
		else{
			cin>>s>>k;
			for(int i=1;i<=k;i++)
				pd[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
		ans+=!pd[i];
	if(ans<1)cout<<-1;
	else cout<<ans;
	return 0;
}