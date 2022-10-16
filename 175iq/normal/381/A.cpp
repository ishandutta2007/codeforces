
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n ;
	cin>>n ;
	vector<int> v(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	int i = 0, j = n-1 ;
	int s1=0, s2=0 ;
	int a ;

while(1)
{
	a=max(v[i],v[j]);
	s1+=a; 
	if(v[i]==a)
	{
		i++;
	}
	else
	{
		j--;
	}
    if(i>j)
    {
        break;
    }
	a=max(v[i],v[j]);
	s2+=a; 	
	if(v[i]==a)
	{
		i++;
	}
	else
	{
		j--;
	}
	    if(i>j)
    {
        break;
    }
}
cout<< s1 <<" "<< s2;
return 0 ;
}