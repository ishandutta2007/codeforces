#include<bits/stdc++.h>
using namespace std;
int n,ans;
map <string,int> c;
string s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s,c[s]++;
	for(int i=1;i<=n;i++)
		cin>>s,ans+=(c[s]<1),c[s]--;
	cout<<ans;
	return 0;
}