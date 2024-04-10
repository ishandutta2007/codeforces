#include<bits/stdc++.h>
using namespace std;
#define bt 127
#define sh 32767
#define it 2147483647
#define ll 9223372036854775807
long double b;
int main()
{
	cin>>b;
	if(b<=bt&&b>=-bt-1)cout<<"byte";
	else if(b<=sh&&b>=-sh-1)cout<<"short";
	else if(b<=it&&b>=-it-1)cout<<"int";
	else if(b<=ll&&b>=-ll-1)cout<<"long";
	else cout<<"BigInteger";
	return 0;
}