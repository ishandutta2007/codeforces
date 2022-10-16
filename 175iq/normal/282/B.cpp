#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;

	int a,g;
	long long int A_sum=0;
	long long int G_sum=0;

	string S;
	int temp1;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>g;
		temp1=A_sum+a;
		if(abs(temp1-G_sum)>500)
		{
			G_sum+=g;
			cout<<"G";
		}
		else
		{
			A_sum+=a;
			cout<<"A";
		}
	}
    /*
	if(abs(A_sum-G_sum)<=500)
	{
		cout<<S;
	}
	else
	{
		cout<<"-1";
	}
	*/
	return 0;
}