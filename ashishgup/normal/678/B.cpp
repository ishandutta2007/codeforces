#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int check_leap(int n)
{
	if(n%400==0)
		return 1;
	if(n%4==0 && n%100!=0)
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	int y;
	cin>>y;
	int ans=y, diff=0;
	do
	{	
		if(check_leap(ans))
			diff+=366;
		else
			diff+=365;
		diff%=7;
		ans++;
	}while(diff!=0 || check_leap(y)!=check_leap(ans));
	cout<<ans;
	return 0;
}