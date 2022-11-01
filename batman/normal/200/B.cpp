#include <bits/stdc++.h>
using namespace std;
int n,a,sum;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a,sum+=a;
	cout<<setprecision(10)<<fixed<<(double)sum/n;
    return 0;
}