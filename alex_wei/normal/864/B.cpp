#include<bits/stdc++.h>
using namespace std;
int n,k[27],cnt,ans;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]<'a')ans=max(ans,cnt),cnt=0,memset(k,0,sizeof(k));
		else cnt+=!k[s[i]-'a'],k[s[i]-'a']=1;
	}
	cout<<max(ans,cnt);
	return 0;
}