#include<bits/stdc++.h>
using namespace std;
string s,s1;
int ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>s;
	ans=0;
	for(int i=s.size()-1;i>=0;i-=2){
		s1="";
		for(int j=0;j<s.size();j++)
			s1+="0";
		s1[i]='1';
		if(s>s1)ans++;
	}
	cout<<ans<<endl;
	return 0;
}