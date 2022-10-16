#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	if(a==b)
	{
		cout<<-1;
		return 0;
	}
	cout<<max(a.size(),b.size());
	return 0;
}