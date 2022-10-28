#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	string str="";
	int cnt=0;
	char ch='?';
	for(auto it:s)
	{
		if(it==ch)
		{
			cnt++;
			if(cnt<=2)
				str+=it;
		}
		else
		{
			str+=it;
			cnt=1;
			ch=it;
		}
	}
	ch='?';
	string ans="";
	int prevcnt=0;
	cnt=0;
	for(auto it:str)
	{
		if(it==ch)
		{
			cnt++;
			if(!(cnt==2 && prevcnt==2))
			{
				ans+=it;
			}
			else
			{
				cnt--;
			}
		}
		else
		{
			ans+=it;
			prevcnt=cnt;
			cnt=1;
			ch=it;
		}
	}
	cout<<ans;
}