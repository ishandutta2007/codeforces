#include<iostream>
using namespace std;
int p[4]={4,9,6,15};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		if(n>=p[n%4])
		{
			if(n%4==3)
				cout<<2+(n-p[n%4])/4<<endl;
			else
				cout<<1+(n-p[n%4])/4<<endl;
		}
		else
			cout<<-1<<endl;	
	}	
	return 0;
}