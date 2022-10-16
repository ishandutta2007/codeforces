#include<bits/stdc++.h>
using namespace std;
string s="hello",k;
int p;
int main()
{
	cin>>k;
	for(int i=0;i<k.size();i++)
		if(p<5&&k[i]==s[p])p++;
	if(p<5)cout<<"NO";
	else cout<<"YES";
	return 0;
}