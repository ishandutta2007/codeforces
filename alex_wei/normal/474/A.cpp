#include<bits/stdc++.h>
using namespace std;
string a="qwertyuiopasdfghjkl;zxcvbnm,./",s;
char p;
int main()
{
	cin>>p>>s;
	for(int i=0;i<s.size();i++)
		for(int j=0;j<a.size();j++)
			if(s[i]==a[j])
				cout<<a[j+(p=='R'?-1:1)];
    return 0;
}