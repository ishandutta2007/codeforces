#include<bits/stdc++.h>
using namespace std;
char t,a,b,c,d;
map <char,int> k;
int main()
{
	cin>>t>>a>>b>>c>>d;
	k['6']=1,k['7']=2,k['8']=3,k['9']=4,k['T']=5,k['J']=6,k['Q']=7,k['K']=8,k['A']=9;
	if((b==d&&k[a]>k[c])||(b==t&&d!=t))cout<<"YES";
	else cout<<"NO";
	return 0; 
}