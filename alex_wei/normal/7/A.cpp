#include<bits/stdc++.h>
using namespace std;
char c[8][8];
int ans,a[8],b[8];
int main()
{
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			cin>>c[i][j],a[i]+=(c[i][j]=='B'),b[j]+=(c[i][j]=='B');
	for(int i=0;i<8;i++)
		if(a[i]==8){
			for(int j=0;j<8;j++)b[j]--;
			ans++;
		}
	for(int j=0;j<8;j++)if(b[j])ans++;
	cout<<ans; 
    return 0;
}