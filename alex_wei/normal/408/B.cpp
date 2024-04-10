#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
int buc1[26],buc2[26];
int ans;
int main(){
	cin>>s>>t;
	for(int i=0;i<s.size();i++)buc1[s[i]-'a']++;
	for(int i=0;i<t.size();i++)buc2[t[i]-'a']++;
	for(int i=0;i<26;i++){
		if(buc2[i]&&!buc1[i])puts("-1"),exit(0);
		ans+=min(buc1[i],buc2[i]);
	}
	cout<<ans<<endl;
    return 0;
}