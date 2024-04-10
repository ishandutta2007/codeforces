#include<bits/stdc++.h>
using namespace std;
string s[8]={"vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"},t;
int n,pd;
int main()
{
	cin>>n>>t;
	for(int i=0;i<8;i++){
		pd=0;
		if(n!=s[i].size())pd=1;
		else
			for(int j=0;j<s[i].size();j++)
				if(s[i][j]!=t[j]&&t[j]!='.')pd=1;
		if(!pd)cout<<s[i],exit(0);
	}
	return 0;
}