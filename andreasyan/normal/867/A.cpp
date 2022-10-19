#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int n;
string a;
int S,F;
int main()
{
	cin>>n>>a;
	for(int i=1;i<n;++i)
	{
		if(a[i]=='S' && a[i-1]=='F')
			++S;
		if(a[i]=='F' && a[i-1]=='S')
			++F;
	}
	if(F>S)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
//	system("pause");
	return 0;
}