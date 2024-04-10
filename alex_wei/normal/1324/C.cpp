#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,a[200005];
string s;
int main(){
	cin>>t;
	while(t--){
		cin>>s;
		int ans=0,cnt=1;
		for(int i=0;i<s.size();i++)if(s[i]=='R')a[cnt++]=i+1;
		a[cnt++]=s.size()+1;
		for(int i=1;i<cnt;i++)ans=max(ans,a[i]-a[i-1]);
		cout<<ans<<endl;
	}
    return 0;
}