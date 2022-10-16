#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	string S;
	cin>>S;

	string ans;
	if(n%2!=0)
	{
	    int i=S.size()-2;
	    int j=0;
	    for ( ; i >=1 ; i-=2)
	    {
		    ans.push_back(S[i]);
	    }
	    for ( ; j <=S.size()-1 ; j+=2)
	    {
		    ans.push_back(S[j]);
	    }
	    cout<<ans ;
	}
	else
	{
	    int i=S.size()-2;
	    int j=1;
	    for ( ; i >=0 ; i-=2)
	    {
		    ans.push_back(S[i]);
	    }
	    for ( ; j <=S.size()-1 ; j+=2)
	    {
		    ans.push_back(S[j]);
	    }
	    cout<<ans ;	        
	}
	return 0;
}