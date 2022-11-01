#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int a,b,ans;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
    	if(s[i]=='+')
    	{
    		if(b)
    			b--,a++;
    		else
    			a++,ans++;
    			
    	}
    	else if(a)
			a--,b++;
		else
			b++,ans++;		
    }	
    cout<<ans;
    return  0;
}