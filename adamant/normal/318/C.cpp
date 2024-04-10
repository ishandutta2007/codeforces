# include <iostream>
using namespace std;
long long a,b,c,s;
main()
{
	cin>>a>>b>>c;
	if(a<b)swap(a,b);
	if(a<1) {cout<<(a<c?-1:0);goto A;}
	b<0&&a<c?s=(a-b)/a, b+=s*a:0;
	while(a<c && b<c)
	a>b?b+=a:a+=b,s++;
	cout<<s;A:;
}