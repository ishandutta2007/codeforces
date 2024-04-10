#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cout<<(i%2?n-i/2:1+i/2)<<" ";
    return 0;
}