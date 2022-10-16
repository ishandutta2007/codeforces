#include<bits/stdc++.h>
using namespace std;
int a,b,c,d; 
int main()
{
	cin>>a>>b>>c>>d;
	cout<<2*(max(2,abs(a-c)+1)+max(2,abs(b-d)+1));
	return 0;
}