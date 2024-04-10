#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int d,k;
		cin>>d>>k;
		int aa=sqrt(1ll*d*d/k/k/2);
		if(2ll*aa*aa+2*aa+1<=1ll*d*d/k/k)puts("Ashish");
		else puts("Utkarsh");
	}
	return 0;
}