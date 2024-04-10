#include<bits/stdc++.h>
using namespace std;
int n,p[10];
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='4')p[3]++,p[2]+=2;
		else if(s[i]=='6')p[3]++,p[5]++;
		else if(s[i]=='8')p[7]++,p[2]+=3;
		else if(s[i]=='9')p[7]++,p[3]+=2,p[2]++;
		else p[s[i]-'0']++;
	}
	for(int i=9;i>1;i--)
		for(int j=0;j<p[i];j++)
			cout<<i;
	return 0;
}