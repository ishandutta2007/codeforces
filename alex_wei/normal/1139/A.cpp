#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
int main()
{
	cin>>s>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]%2==0)
			n+=i+1;
	cout<<n;
    return 0;
}