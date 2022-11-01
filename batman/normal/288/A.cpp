#include <iostream>
#include <vector>
using namespace std;
#define ll long long


ll a,b;
int main() {
	cin>>a>>b;
	if(a<b || (b==1 && a>1))
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<a-b;i++)
	{
		if(i%2==0)
			cout<<'a';
		else
			cout<<'b';	
	}
	if((a-b)%2==0)
	{
		for(int i=0;i<b;i++)
		{
			char ex=i+'a';
			cout<<ex;
		}
		return 0;
	}
	cout<<'b';
	for(int i=0;i<b;i++)
	{
		if(i==1)
			i++;
		if(i>=b)
			break;
		char ex=i+'a';
		cout<<ex;	
	}
						
	return 0;
}