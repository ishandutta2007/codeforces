#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
multiset<int> s;
vector<string> ans;

void insert(int x)
{
	string str="insert ";
	str+=to_string(x);
	ans.push_back(str);
}

void getMin(int x)
{
	string str="getMin ";
	str+=to_string(x);
	ans.push_back(str);
}

void removeMin()
{
	string str="removeMin";
	ans.push_back(str);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		if(str=="insert")
		{
			int x;
			cin>>x;
			s.insert(x);
			insert(x);
		}
		else if(str=="getMin")
		{
			int x;
			cin>>x;
			while(s.size() && *s.begin() < x)
			{
				removeMin();
				s.erase(s.begin());
			}
			if(s.size() && *s.begin()==x)
				getMin(x);
			else
			{
				insert(x);
				s.insert(x);
				getMin(x);
			}
		}
		else
		{
			if(s.size())
			{
				s.erase(s.begin());
				removeMin();
			}
			else
			{
				insert(1);
				removeMin();
			}
		}
	}	
	cout<<ans.size()<<endl;
	for(auto &it:ans)
		cout<<it<<endl;
	return 0;
}