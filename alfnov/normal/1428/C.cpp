#include<bits/stdc++.h>
using namespace std;
char s[1000005];
stack<char>st;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",s+1);
		while(st.size())st.pop();
		int n=strlen(s+1);
		for(int i=1;i<=n;i++)
		{
			st.push(s[i]);
			if(st.size()>=2&&st.top()=='B')
			{
				st.pop();
				st.pop();
			}
		}
		cout<<st.size()<<endl;
	}
	return 0;
}