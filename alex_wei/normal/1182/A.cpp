#include<bits/stdc++.h>
using namespace std;
int n; 
int main()
{
	cin>>n;
	cout<<(n%2?0:(1<<(n/2)));
	return 0;
}