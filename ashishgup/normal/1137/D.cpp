#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

void query(int x)
{
	cout<<"next "<<x<<endl;
}

bool read()
{
	int k;
	cin>>k;
	bool check = 0;
	for(int i=1;i<=k;i++)
	{
		string s;
		cin>>s;
		int have0 = 0, have1 = 0;
		for(auto &it:s)
		{
			have0 |= (it=='0');
			have1 |= (it=='1');
		}
		check |= (have0 && have1);
	}
	if(k==1)
	{
		cout<<"done";
		exit(0);
	}
	return check;
}

bool move(int x, int k)
{
	bool last = 0;
	for(int i=1;i<=k;i++)
	{
		query(x);
		last = read();
	}
	return last;
}

void work()
{
	int slow = 0, fast = 1;
	bool check = 0;
	while(!check)
	{
		cout<<"next ";
		for(int i=0;i<=1;i++)
			cout<<i<<" ";
		cout<<endl;
		read();
		check = move(fast, 1);
	}
	while(true)
	{
		cout<<"next ";
		for(int i=0;i<=9;i++)
			cout<<i<<" ";
		cout<<endl;
		read();
	}
}

int32_t main()
{
	IOS;
	work();
	return 0;
}