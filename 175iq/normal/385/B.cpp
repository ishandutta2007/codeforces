#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin>>S;
	int n=S.size();
	string target="bear";
	long long int count=0;
	int pos=-4;
	int ex=-1;
	while( ( pos=S.find(target,pos+4) ) != string::npos)
	{
		count+=(pos-ex)*(n-(pos+3)) ;
		ex=pos;
	}
	cout<<count;
	return 0;
}