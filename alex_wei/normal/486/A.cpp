#include<bits/stdc++.h>
using namespace std;
long long n; 
int main()
{
	cin>>n;
	cout<<n/2-(n%2?n:0);
	return 0;
}