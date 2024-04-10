#include <bits/stdc++.h>
using namespace std;
long long n,t;
int main()
{
	cin>>t;
	for(int i=0;i<t;i++)
		cin>>n,cout<<(long long)((1+n)*n/2-2*((1<<((int)log2(n)+1))-1))<<endl;
    return 0;
}