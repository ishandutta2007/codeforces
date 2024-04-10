#include <bits/stdc++.h>
using namespace std;
int n,f=1;
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
		f=(f+i-1)%n+1,cout<<f<<" ";
    return 0;
}