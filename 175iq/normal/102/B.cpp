#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int sum=0;
	int count=0;

	while(1)
	{	
	    if(s.size()==1)
	    {
	        break;
	    }
	    sum=0;
		for (int i = 0; i < s.size(); ++i)
		{
			sum+=(s[i]-'0');
		}
		s.clear();	
		s=to_string(sum);
		//cout<<"Sum is "<<sum <<"and S is "<<s<<endl;
		count++;
	}
	cout<<count;
	return 0;
}