#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s ;
	getline(cin,s) ;
	string ::iterator ptr1,ptr2;
	ptr1=s.begin();
	ptr2=ptr1;
	ptr1=ptr1+1;
	transform(ptr2,ptr1,ptr2,::toupper);
	cout<<s;
	return 0;
}