#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int N=1000006;

int n,m;
char k;
char a[N];
int ans;
stack<char> s;
int main()
{
	int i,j;
	scanf("%s",&a);
	n=strlen(a);
	for(i=0;i<n;++i)
	{
		if(a[i]=='<' || a[i]=='[' || a[i]=='{' || a[i]=='(')
		{
			s.push(a[i]);
		}
		else
		{
			if(s.empty())
			{
				cout<<"Impossible"<<endl;
				return 0; 
			}
			k=s.top();
			s.pop();
			if((k=='<' && a[i]=='>') || (k=='[' && a[i]==']') || (k=='{' && a[i]=='}') || (k=='(' && a[i]==')'))
			{
				continue;
			}
			++ans;
		}
	}
	if(!s.empty())
	{
		cout<<"Impossible"<<endl;
		return 0; 
	}
	cout<<ans<<endl;
	return 0;
}