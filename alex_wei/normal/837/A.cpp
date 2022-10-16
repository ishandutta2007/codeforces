#include<bits/stdc++.h>
using namespace std;
string s;
int ans,cnt,n; 
int main()
{
	cin>>n;
	while(cin>>s){
		cnt=0;
		for(int i=0;i<s.size();i++)
			if(s[i]<='Z')cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}