
#include <bits/stdc++.h>
using namespace std;

int n,a;
int main()
{ 
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a;
    	if(a==1)
    	{
    		cout<<-1;
    		return 0;
    	}
    }
    cout<<1;	
	return 0;
}