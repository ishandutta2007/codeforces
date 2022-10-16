#include<bits/stdc++.h>
using namespace std;
string s;
int p[26]; 
int main()
{
	for(int i=0;i<3;i++){
		cin>>s;
		for(int j=0;j<s.size();j++)
			p[s[j]-'A']+=(i<2?1:-1);
	}
	for(int j=0;j<26;j++)
		if(p[j]!=0)
			cout<<"NO",exit(0);
	cout<<"YES";
	return 0;
}