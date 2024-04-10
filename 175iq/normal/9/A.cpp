#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::vector<string> vec{"1/6","1/3","1/2","2/3","5/6","1/1"} ;
	int a,b ;
	cin>>a>>b ;
	int c = max(a,b);
	cout<<vec[6-c];
	return 0;
}