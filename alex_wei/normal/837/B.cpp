#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[102];
void row()
{
	if(s[0][0]==s[n/3][0]||s[0][0]==s[n/3*2][0]||s[n/3][0]==s[n/3*2][0])
		return;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]!=s[(i/(n/3))*(n/3)][0])
				return;
	cout<<"YES",exit(0);
}
void clm()
{
	if(s[0][0]==s[0][m/3]||s[0][0]==s[0][m/3*2]||s[0][m/3]==s[0][m/3*2])
		return;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]!=s[0][(j/(m/3))*(m/3)])
				return;
	cout<<"YES",exit(0);
}
int main()
{
	cin>>n>>m;
	if(n%3&&m%3)cout<<"NO",exit(0);
	for(int i=0;i<n;i++)
		cin>>s[i];
	if(n%3==0)
		row();
	if(m%3==0)
		clm();
	cout<<"NO";
	return 0;
}