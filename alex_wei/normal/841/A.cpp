#include<bits/stdc++.h>
using namespace std;
#define ac akkk
int n,k,t[26];
string s;
int main()
{
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		t[s[i]-'a']++;
		if(t[s[i]-'a']>k)cout<<"NO",exit(0);
	}
	cout<<"YES";
	return 0;
}