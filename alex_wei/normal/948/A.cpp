#include<bits/stdc++.h>
using namespace std;
int r,c;
char s[502][502];
int main()
{
	cin>>r>>c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin>>s[i][j];
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if(s[i][j]=='W'){
				if(s[i+1][j]=='S'||s[i][j+1]=='S'||s[i-1][j]=='S'||s[i][j-1]=='S')cout<<"No",exit(0);
				if(s[i+1][j]=='.')s[i+1][j]='D';
				if(s[i][j+1]=='.')s[i][j+1]='D';
				if(s[i-1][j]=='.')s[i-1][j]='D';
				if(s[i][j-1]=='.')s[i][j-1]='D';
			}
	cout<<"Yes\n";
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++)cout<<s[i][j];
		cout<<endl;
	}
	return 0;
}