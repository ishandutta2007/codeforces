#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	int i=1;
	for(;;i++)
	{
		a*=3;
		b*=2;
		if(a>b)
		{
			break;
		}
	}

	//int answer=ceil( ( log10(b/a) ) / ( log10(1.5) ) );
	cout<<i;

	return 0;
}