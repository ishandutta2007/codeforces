#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		string s;cin>>s; 
		for(int i=0;i<s.size();i++)
			if(i%2)
				if(s[i]=='z')
					s[i]='y';
				else
					s[i]='z';
			else
				if(s[i]=='a')
					s[i]='b';
				else
					s[i]='a';
		cout<<s<<endl;
	}
}