#include<bits/stdc++.h>
using namespace std;
unsigned long long b=45,bas=1,a;
void print()
{
	for(int i=1;i<=18;i++)bas=bas*10;
	b=(8*(10*bas%a)+bas)%a;
	b++;
}
int main()
{
	cin>>a;
	print();
	cout<<1+a-b<<" "<<bas+a-b;
	return 0;
}