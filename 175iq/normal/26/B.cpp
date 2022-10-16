#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin>>S;

	stack<char> s;
	char c;
	int count=0;
	for (int i = 0; i < S.size(); ++i)
	{
		if(S[i]=='(')
		{
			s.push('(');
		}
		else if(S[i]==')')
		{
		    if(!s.empty())
		    {
    			c=s.top();
    			s.pop();
    			if(c=='(')
    			{
    				count+=2;
    			}
		    }
		}
	}
	cout<<count;
	return 0;
}