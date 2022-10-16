#include<bits/stdc++.h>
using namespace std;
int tp[26],n,ans;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n-1;i++){
		tp[s[i*2]-'a']++;
		if(!tp[s[i*2+1]-'A'])ans++;
		else tp[s[i*2+1]-'A']--;
	}
	cout<<ans;
	return 0;
}