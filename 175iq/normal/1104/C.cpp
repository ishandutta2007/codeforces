#include <bits/stdc++.h>
using namespace std;

int main()
{	
	string s;
	cin>>s;

	int n=s.size();

	int h=1;
	int v=1;
	bool f=0;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='0')
		{
			cout<<1<<" "<<v<<endl;
			v++;
			if(v==5)
			{
				v=1;
			}
		}
		else
		{
			if(f==0)
			{
       			cout<<3<<" "<<1<<endl;
       			f=1-f;         
			}
			else
			{
				cout<<3<<" "<<3<<endl;
				f=1-f;
			}
		}
	}
	return 0;
}