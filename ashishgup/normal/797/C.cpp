#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

string str, ans="";
queue<char> q;
stack<char> s;
multiset<char> m;
priority_queue<char, vector<char>, greater<char> > pq;

int32_t main()
{
	IOS;
	cin>>str;
	for(auto it:str)
	{
		q.push(it);
		m.insert(it);
	}
	int ind=-1;
	int n=str.size();
	while(ans.size() != n)
	{
	 	s.push(q.front());
	 	q.pop();
	 	ind++;
	 	m.erase(m.find(str[ind]));
	 	while(s.size() && m.size() && (*(m.begin())>=s.top()))
	 	{
	 		ans+=s.top();
	 		s.pop();
	 	}
	 	if(q.empty())
	 	{
	 		while(s.size())
	 		{
	 			ans+=s.top();
	 			s.pop();
	 		}
	 	}
	}
	cout<<ans;
}