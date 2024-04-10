#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int n;
	cin>>n;
	string s;
	cin>>s;

	string t;
	t=s;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='R')
		{
			t[i]='0';
		}
		else if(s[i]=='G')
		{
			t[i]='1';
		}
		else if(s[i]=='B')
		{
			t[i]='2';
		}
	}
	int ans=0;
	int temp;
//	cout<<s<<endl;
//	cout<<t<<endl;
	for (int i = 1; i<n; ++i)
	{
		if(s[i]==s[i-1])
		{
			ans++;
			if(i+1<=n-1)
			{
				if(s[i-1]!=s[i+1])
				{
					temp=(t[i-1]-'0')+(t[i+1]-'0');
					if(temp==1)
					{
						s[i]='B';
						//t[i]='2';
					}
					else if(temp==2)
					{
						s[i]='G';
						//t[i]='1';
					}
					else if(temp==3)
					{
						s[i]='R';
						//t[i]='0';
						//cout<<"vjr"<<endl;
					}					
				}
				else if(s[i-1]==s[i+1])
				{
					if(s[i-1]=='R')
					{
						s[i]='G';
						//t[i]='1';
					}
					else if(s[i-1]=='G')
					{
						s[i]='B';
						//t[i]='2';
					}
					else if(s[i-1]=='B')
					{
						s[i]='R';
						//t[i]='0';
					}					
				}
			}
			else
			{
				if(s[i-1]=='R')
				{
					s[i]='G';
					//t[i]=1;
				}
				else if(s[i-1]=='G')
				{
					s[i]='B';
					//t[i]='2';
				}
				else if(s[i-1]=='B')
				{
					s[i]='R';
					//t[i]='0';
				}
			}
		}
	}
	cout<<ans<<endl;
	cout<<s<<endl;
	//cout<<t;
	
	return 0;
}