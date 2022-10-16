#include<bits/stdc++.h>
using namespace std;
string s;
int a[26];
int main()
{
	cin>>s;
	if(s.size()<26)puts("-1"),exit(0);
	for(int i=0;i+26<=s.size();i++){
		memset(a,0,sizeof(a));
		for(int j=i;j<i+26;j++)
			if(s[j]!='?')a[s[j]-'A']++;
		int pd=1;
		for(int j=0;j<26;j++)
			if(a[j]>1)pd=0;
		if(pd){
			for(int j=i;j<i+26;j++)
				if(s[j]=='?'){
					for(int k=0;k<26;k++)
						if(!a[k]){
							s[j]=k+'A';
							a[k]=1;
							break;
						}
				}
			for(int j=0;j<s.size();j++)
				if(s[j]=='?')
					s[j]='A'; 
			cout<<s<<endl,exit(0);
		}
	}
	puts("-1");
    return 0;
}