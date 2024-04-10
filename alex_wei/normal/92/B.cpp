#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int ans;
int main(){
	cin>>s;
	for(int i=s.size()-1;;i--){
		if(i==0)cout<<ans+(s[i]=='2'),exit(0);
		if(s[i]=='2')s[i-1]++,ans++;
		else if(s[i]=='1')ans+=2,s[i-1]++;
		else ans++;
	}
	return 0;
}