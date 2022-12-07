#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int n,ans=0,a[233];
string s,ss;
map<string,int>mp;

int main() {
	cin>>n;
	mp.clear();
	for (int i=1;i<=n;i++){
		cin>>s;
		ss="";
		memset(a,0,sizeof a);
		for (int j=s.length()-1;j>=0;j--){
			if (s[j]=='h')
				a[j]=1;
			if (s[j]=='k')
				a[j]=a[j+1];
		}
		for (int j=0;j<s.length();j++){
			if (s[j]=='k'){
				if (!a[j])
					ss+=s[j];
			}else if (s[j]=='u'){
				ss+='o';
				ss+='o';
			}else{
				ss+=s[j];
			}
		}
		if (mp.count(ss)) continue;
		mp[ss]=1;
		ans++;
	}
	cout<<ans;
}