#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin>>S;
	string ans;
	for (int i = 0; i < S.size(); ++i)
	{
		if((S[i]=='A') || (S[i]=='E') || (S[i]=='I') || (S[i]=='O') || (S[i]=='Y') || (S[i]=='U')||(S[i]=='a') || (S[i]=='e') || (S[i]=='i') || (S[i]=='o') || (S[i]=='u') || (S[i]=='y'))
		{
		    continue;
		}	
		else
		{
			char c=tolower(S[i]);
			ans+=".";
			ans+=c;
		}
	}
	cout<<ans;
	return 0;
}