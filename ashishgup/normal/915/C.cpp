#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

string a, b;
map<char, int> m;

string get_string(int index)
{
	string ans="";
	string c=a;
	for(char ch='0';ch<='9';ch++)
	{
		if(index==0&&ch=='0')
			continue;
		bool check=true;
		if(ch>=b[index])
			continue;
		map<char, int> m2=m;
		if(!m2[ch])
			continue;
		c[index]=ch;
		m2[ch]--;
		for(int i=0;i<index;i++)
		{
			char ch2=b[i];
			while(!m2[ch2]&&ch2>='0')
				ch2--;
			if(ch2>='0'&&ch2<='9')
			{
				c[i]=ch2;
				m2[ch2]--;
			}
			else
			{
				check=false;
			}
		}
		for(int i=index+1;i<a.size();i++)
		{
			char ch2='9';
			while(m2[ch2]<=0&&ch2>='0')
				ch2--;
			if(ch2>='0'&&ch2<='9')
			{
				c[i]=ch2;
				m2[ch2]--;
			}
			else
			{
				check=false;
			}
		}
		if(check&&c<=b)
			ans=max(ans, c);
	}
	return ans;
}

int32_t main() 
{
	IOS;
	cin>>a>>b;
	for(auto it:a)
	{
		m[it]++;
	}
	if(a.size()<b.size())
	{
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		cout<<a;
		return 0;
	}
	string c=a;
	string d=b;
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	if(c==d)
	{
		cout<<b;
		return 0;
	}
	string ans="";
	for(int i=0;i<a.size();i++)
	{
		string cur=get_string(i);
		if(cur=="-1")
			continue;
		ans=max(ans, cur);
	}
	cout<<ans;
}