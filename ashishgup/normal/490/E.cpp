#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

string getcur(string &prev, string &cur)
{
	if(cur.size()<prev.size())
		return "-1";
	if(cur.size()>prev.size())
	{
		for(int i=0;i<cur.size();i++)
		{
			if(cur[i]=='?')
			{
				cur[i]=(i==0)?'1':'0';
			}
		}
		return cur;	
	}
	vector<string> posbl;
	bool check=0;
	for(int i=0;i<cur.size();i++)
	{
		if(cur[i]!='?')
		{
			if(cur[i]>prev[i])
			{
				string temp=cur;
				for(auto &it:temp)
				{
					if(it=='?')
						it='0';
				}
				if(temp>prev)
				{
					posbl.push_back(temp);
				}
			}
		}
		if(cur[i]=='?')
		{
			string temp=cur;
			char ch='9';
			temp[i]=min(prev[i]+1, ch+0);
			for(auto &it:temp)
			{
				if(it=='?')
					it='0';
			}
			if(temp>prev)
				posbl.push_back(temp);
		}	
		if(cur[i]=='?')
			cur[i]=prev[i];
	}
	if(cur>prev)
		posbl.push_back(cur);
	if(!posbl.size())
		return "-1";
	sort(posbl.begin(), posbl.end());
	return posbl.front();
}

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    string prev="0";
    vector<string> ans;
    for(int i=1;i<=n;i++)
    {
    	string s;
    	cin>>s;
    	ans.push_back(getcur(prev, s));
    	if(ans.back()=="-1")
    	{
    		cout<<"NO";
    		return 0;
    	}
    	prev=ans.back();
    }
    cout<<"YES"<<endl;
    for(auto it:ans)
    	cout<<it<<endl;
    return 0;
}