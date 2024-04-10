#include <iostream>

#define M 100100

using namespace std;

int m=0;
char t[M];

int main()
{
	char x;
	while (cin>>x){
		if (m>0 && t[m-1]==x)
		m--;
		else
		t[m++]=x;
	}
	if (m==0)
	cout<<"Yes\n";
	else
	cout<<"No\n";
	return 0;
}