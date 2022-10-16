#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s[110],k[11]={"ABSINTH","BEER","BRANDY","CHAMPAGNE","GIN","RUM","SAKE","TEQUILA","VODKA","WHISKEY","WINE"};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		int pd=0;
		if(s[i][0]<='9'){
			if(s[i].size()<2||(s[i].size()==2&&s[i][0]=='1'&&s[i][1]<'8'))pd=1;
		}
		else
			for(int j=0;j<11;j++)if(s[i]==k[j])pd=1;
		ans+=pd;
	}
	cout<<ans;
    return 0;
}