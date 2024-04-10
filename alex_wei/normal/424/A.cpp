#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,c;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		c+=s[i]=='X';
	cout<<abs(c-n/2)<<endl;
	for(int i=0;i<n;i++){
		if(c>n/2&&s[i]=='X')cout<<'x',c--;
		else if(c<n/2&&s[i]=='x')cout<<'X',c++;
		else cout<<s[i];
	}
	return 0;
}