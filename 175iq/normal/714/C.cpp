#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;

	char ch;
	int temp=0;
	string str;
	unordered_map<string,int> M;

	for (int i = 0; i < t; ++i)
	{
		cin>>ch>>str;
		if(ch=='+')
		{	
			for (int i = 0; i < str.size(); ++i)
			{
				if( (str[i]-'0')%2==0 )
				{
			        str[i]='0';	    
				}
				else
				{
				    str[i]='1';
				}
			}
			
			if(str.size() < 18)
			{
				reverse(str.begin(),str.end());
				temp=18-str.size();
				for (int i = 1; i <= temp ; ++i)
				{
					str+='0';
				}
				reverse(str.begin(),str.end());	
			}
			if(M.find(str)==M.end())
			{
				M[str]=1;
			}
			else
			{
				M[str]++;
			}
			
		}

		else if(ch=='-')
		{
			for (int i = 0; i < str.size(); ++i)
			{
				if( (str[i]-'0')%2==0 )
				{
			        str[i]='0';	    
				}
				else
				{
				    str[i]='1';
				}
			}
			int temp=0;
			if(str.size() < 18)
			{
				reverse(str.begin(),str.end());
				temp=18-str.size();
				for (int i = 1; i <= temp ; ++i)
				{
					str+='0';
				}
				reverse(str.begin(),str.end());	
			}
			M[str]--;
		}

		else if(ch=='?')
		{
			if(str.size() < 18)
			{
				reverse(str.begin(),str.end());
				temp=18-str.size();
				for (int i = 1; i <= temp ; ++i)
				{
					str+='0';
				}
				reverse(str.begin(),str.end());	
			}			
			cout<<M[str]<<endl;
		}
	}
	return 0;
}