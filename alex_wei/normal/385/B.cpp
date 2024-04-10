#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int main()
{
	cin>>s;
	for(int i=0;i<(int)s.size()-3;i++)
		for(int j=i;j<(int)s.size()-3;j++)
			if(s[j]=='b'&&s[j+1]=='e'&&s[j+2]=='a'&&s[j+3]=='r'){ans+=(s.size()-j-3);break;}
	cout<<ans;
    return 0;
}