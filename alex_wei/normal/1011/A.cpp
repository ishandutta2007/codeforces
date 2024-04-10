#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,p[27],poi,ans;
int main()
{
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)p[s[i]-'a']+=1;
	for(int i=0;i<k;i++){
		while(poi<26&&!p[poi])poi++;
		if(poi>=26)cout<<-1,exit(0);
		ans+=poi,poi+=2;
	}
	cout<<ans+k;
	return 0;
}