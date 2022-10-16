#include <bits/stdc++.h>
using namespace std;

int main()
{
	long double n,m,a;
	cin>>n>>m>>a;
	long long int b = (ceil (m/a)) *(ceil (n/a));
	cout<<b;
	return 0;
}