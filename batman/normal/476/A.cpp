#include <iostream>

using namespace std;


int main() {
	
	int n,m,min,ans;
	cin>>n>>m;
	
	if(n%2==0)
	  min=n/2;
	if(n%2==1)
	  min=(n/2)+1;  
	   
	int p=0;   
	for(int i=min;i<=n;i++)
	{
		
		if(i%m==0)
		{
			cout<<i<<endl;
			p++;
			break;
		}
	}
	if(p==0)
	  cout<<-1<<endl;
	   
	return 0;
}