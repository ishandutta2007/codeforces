




#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int q;
	cin>>q;

	int l1,r1,l2,r2;

	int a,b;

	for (int i = 0; i < q; ++i)
	{
		cin>>l1>>r1>>l2>>r2;
		if(l1!=r2)
		{
			cout<<l1<<" "<<r2<<endl;
		}
		else
		{
			cout<<l1<<" "<<l2<<endl;
		}
	}
	return 0;
}