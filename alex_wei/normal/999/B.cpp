#include <bits/stdc++.h>
using namespace std;
int n;
string s; 
int main()
{
	cin>>n>>s;
	for(int i=1;i<=s.size();i++)
		if(n%i==0)
			reverse(s.begin(),s.begin()+i);
	cout<<s;
    return 0;
}