#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int prev=0, cnt=0, day=1;
	cin.ignore();
	while(n--)
	{
		string s;
		getline(cin, s);
		string time, check;
		stringstream ss(s);
		ss>>time>>check;
		int hh=(10*(time[1]-'0')+time[2]-'0');
		int mm=(10*(time[4]-'0')+time[5]-'0');
		if(hh==12)
			hh=0;
		if(check[0]=='p')
			hh+=12;
		int cur=hh*60 + mm;
		if(cur==prev)
		{
			cnt++;
			if(cnt==11)
			{
				cnt=1;
				day++;
			}
		}
		else
		{
			if(cur<prev)
				day++;
			prev=cur;
			cnt=1;
		}
	}
	cout<<day;
	return 0;
}