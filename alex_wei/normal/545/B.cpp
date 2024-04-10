#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,cnt;
string s,t; 
int main(){
	cin>>s>>t;
	for(int i=0;i<s.size();i++)cnt+=s[i]!=t[i];
	if(cnt%2)puts("impossible");
	else{
		cnt/=2;
		for(int i=0;i<s.size();i++){
			if(s[i]!=t[i]){
				if(cnt)cout<<s[i],cnt--;
				else cout<<t[i];
			}
			else cout<<0;
		}
	}
    return 0;
}