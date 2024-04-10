#include<bits/stdc++.h>
using namespace std;
auto work=[](){
	string s,t;
	cin>>s>>t;
	reverse(begin(s),end(s));
	reverse(begin(t),end(t));
	int i=0,n=s.size();
	map<int,int>mp;
	for(char c:t){
		for(;i<n&&c!=s[i];++i)++mp[s[i]];
		if(i==n)return cout<<"NO\n",void();
		++i;
		if(mp[c])return cout<<"NO\n",void();
	}
	cout<<"YES\n";
};
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int T;for(cin>>T;T--;)work();
}