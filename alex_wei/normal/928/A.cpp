#include<bits/stdc++.h>
using namespace std;
string s,t;
int n;
int main()
{
	cin>>s>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(s.size()!=t.size())continue;
		int pd=1;
		for(int j=0;j<t.size();j++){
			if(s[j]!=t[j]&&!(abs(s[j]-t[j])=='a'-'A'&&s[j]!='-'&&t[j]!='-')
			&&!(s[j]=='0'&&t[j]=='O'||t[j]=='0'&&s[j]=='O'||s[j]=='0'&&t[j]=='o'||t[j]=='0'&&s[j]=='o'
			||s[j]=='1'&&t[j]=='l'||t[j]=='1'&&s[j]=='l'||s[j]=='1'&&t[j]=='L'||t[j]=='1'&&s[j]=='L'
			||s[j]=='1'&&t[j]=='i'||t[j]=='1'&&s[j]=='i'||s[j]=='1'&&t[j]=='I'||t[j]=='1'&&s[j]=='I'
			||s[j]=='l'&&t[j]=='i'||t[j]=='l'&&s[j]=='i'||s[j]=='l'&&t[j]=='I'||t[j]=='l'&&s[j]=='I'
			||s[j]=='L'&&t[j]=='i'||t[j]=='L'&&s[j]=='i'||s[j]=='L'&&t[j]=='I'||t[j]=='L'&&s[j]=='I'))pd=0;
		}
		if(pd)cout<<"No",exit(0);
	}
	cout<<"Yes";
	return 0;
}