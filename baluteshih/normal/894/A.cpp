#include <iostream>
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main()
{
	string s;
	int i,j,k,ans=0;
	cin >> s;
	for(i=0;i<s.size();i++)
		for(j=i+1;j<s.size();j++)
			for(k=j+1;k<s.size();k++)
				if(s[i]=='Q' && s[j]=='A' && s[k]=='Q') ans++;
	cout << ans << "\n";
}