#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int N=505;

int n;
vector<char> ans, ans2;

bool query(int x1, int y1, int x2, int y2)
{
	if(x1<1 || x1>n || y1<1 || y1>n)
		return 0;
	if(x2<1 || x2>n || y2<1 || y2>n)
		return 0;
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	string s;
	cin>>s;
	return s=="YES";
}

int32_t main()
{
	IOS;
	cin>>n;
	int x=1, y=1;
	while(abs(x-1) + abs(y-1) < n-1)
	{
		if(query(x, y+1, n, n))
		{
			ans.push_back('R');
			y++;
		}
		else
		{
			ans.push_back('D');
			x++;
		}
	}	
	x=n, y=n;
	while(abs(x-n) + abs(y-n) < n-1)
	{
		if(query(1, 1, x-1, y))
		{
			ans2.push_back('D');
			x--;
		}
		else
		{
			ans2.push_back('R');
			y--;
		}
	}
	reverse(ans2.begin(), ans2.end());
	cout<<"! ";
	for(auto &it:ans)
		cout<<it;
	for(auto &it:ans2)
		cout<<it;
	cout<<endl;
	return 0;
}