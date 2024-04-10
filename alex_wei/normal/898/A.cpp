#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	cout<<(n%10<5?n-n%10:n-n%10+10);
	return 0;
}