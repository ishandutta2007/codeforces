#include <bits/stdc++.h>
using namespace std;

int main()
{	
	string s;
	cin>>s;
	
	stack<char> st;

	int n = s.size();
	bool win=1; 
	for (int i = 0; i < n; )
	{
		if(st.empty())
		{
			st.push(s[i]);
			i++;
		}
		else if(st.top()==s[i])
		{
			win=1-win;
			st.pop();
			i++;
			//cout<<"boom"<<endl;
		}
		else
		{
			st.push(s[i]);
			i++;
		}
	}

	if(win==0)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}