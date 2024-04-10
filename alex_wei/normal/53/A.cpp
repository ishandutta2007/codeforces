#include<bits/stdc++.h>
using namespace std;
int n,pd;
string s,b,ans;
int main()
{
	cin>>s>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		if(b.find(s)==0){
			if(!pd)ans=b;
			else ans=min(ans,b);
			pd++;
		}
	}
	if(pd)cout<<ans;
	else cout<<s;
    return 0;
}