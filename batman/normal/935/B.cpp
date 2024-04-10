#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

int n,x,y,ans;
string s;
bool now;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	if(s[0]=='U')now=0,y++;
	else now=1,x++;
	for(int i=1;i<n;i++)
	{
		if(s[i]=='U')y++;
		else x++;
		if(x>y && now==0)now=1,ans++;
		if(x<y && now==1)now=0,ans++;
	}
	cout<<ans<<"\n";
	return 0;
}