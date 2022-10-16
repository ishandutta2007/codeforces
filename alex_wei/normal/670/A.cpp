#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int main()
{
	cin>>n;
	int wk=n/7;
	cout<<wk*2+(n%7==6)<<" "<<wk*2+(n%7>0)+(n%7>1);
	return 0;
}