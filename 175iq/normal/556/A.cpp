#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string S;
	cin>>S;

	int zero=0,one=0;
	for (int i = 0; i < S.size(); ++i)
	{
		if(S[i]=='0')
		{
			zero++;
		}
		else
		{
			one++;
		}
	}

	int ans=abs(one-zero);
	cout<<ans;
	return 0;
}