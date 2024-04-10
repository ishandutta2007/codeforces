#include<bits/stdc++.h>
using namespace std;
string ans,t,s,t2;
const int N=1e6+3;
int p[N];
int kmp(const string&s,const string&t){
	int i,j,l,lt;
	for(i=1,j=p[0]=-1,l=s.size();i<l;++i){
		while(j>=0&&s[j+1]!=s[i])j=p[j];
		if(s[j+1]==s[i])p[i]=++j;else p[i]=-1;
	}
	for(i=0,j=-1,lt=t.size();i<lt;++i){
		while(j>=0&&j+1<l&&s[j+1]!=t[i])j=p[j];
		if(j+1<l&&s[j+1]==t[i])++j;
	}
	return j+1;
}
int main(){
	int n,l;
	ios::sync_with_stdio(0),cin>>n;
	while(n--){
		cin>>t,l=t.size();
		s=ans.substr(max((int)ans.size()-l,0)),reverse(s.begin(),s.end());
		t2=t,reverse(t2.begin(),t2.end());
		ans+=t.substr(kmp(s,t2));
	}
	cout<<ans;
	return 0;
}