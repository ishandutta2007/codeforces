#include<bits/stdc++.h>
using namespace std;
int x,c;
int main()
{
	cin>>x;
	while(x)c+=x&1,x>>=1;
	cout<<c;
    return 0;
}