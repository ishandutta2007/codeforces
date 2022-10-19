#include<bits/stdc++.h>
using namespace std;
int np[31]={0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a;
		if(a>30)
		{
			if(a==36)
			{
				cout<<"YES"<<endl<<"5 6 10 15"<<endl;
			}else if(a==40)
			{
				cout<<"YES"<<endl<<"6 10 15 9"<<endl;
			}else if(a==44)
			{
				cout<<"YES"<<endl<<"6 7 10 21"<<endl;
			}else cout<<"YES"<<endl<<"6 10 14"<<" "<<a-30<<endl;
		}else cout<<"NO"<<endl;
	}
	return 0;
}