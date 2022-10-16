#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int t;
int main(){
	cin>>t;
	while(t--){
		cin>>s;
		int pd=1;
		for(int i=1;i<s.size();i++)
			if(s[i]==s[i-1]&&s[i]!='?')
				pd=0;
		if(!pd){
			cout<<"-1\n";continue;
		}
		for(int i=0;i<s.size();i++){
			if(s[i]=='?'){
				if(i==0){
					s[i]='a';
					if(i<s.size()-1&&s[i]==s[i+1])s[i]++;
					if(s[i]=='d')s[i]='a';
					continue;
				}
				s[i]=(s[i-1]+1);
				if(s[i]=='d')s[i]='a';
				if(i<s.size()-1&&s[i]==s[i+1])s[i]++;
				if(s[i]=='d')s[i]='a';
			}
		}
		cout<<s<<endl;
	}
    return 0;
}