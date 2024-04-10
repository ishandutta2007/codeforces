#include<bits/stdc++.h>
using namespace std;
int n;
string s;
void bad()
{
	for(int i=0;i<n;i++)
		if(s[i]=='1'||s[i]=='2'||s[i]=='3')
			cout<<"YES",exit(0);
	cout<<"NO";
	exit(0);
}
void good()
{
	int p[10];
	memset(p,0,sizeof(p));
	for(int i=0;i<n;i++)
		p[s[i]-'0']=1;
	if(p[1]&&p[9]||p[3]&&p[7]||p[1]&&p[6]&&p[7]||p[3]&&p[4]&&p[9]||p[7]&&p[9]&&p[2]||p[7]&&p[6]&&p[2]||p[9]&&p[2]&&p[4])cout<<"YES";
	else cout<<"NO";
	exit(0);
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='0')bad();
	good();
	return 0;
}