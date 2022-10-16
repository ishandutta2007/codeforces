#include<bits/stdc++.h>
using namespace std;
int n,m,e[1002][5],ans,a;
string s;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=m;j++)
			e[j][s[j-1]-'A']++;
	}
	for(int i=1;i<=m;i++){
		cin>>a;
		ans+=max(e[i][0],max(e[i][1],max(e[i][2],max(e[i][3],e[i][4]))))*a;
	}
	cout<<ans;
	return 0;
}