#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, to_have=0;
int have[N];
vector<string> types, ans;

void generate(string s, int len)
{
	if(len==4)
	{
		for(int i=1;i<=3;i++)
		{
			s+='#';
			types.push_back(s);
		}
		return;
	}
	string temp="";
	for(int i=1;i<=3;i++)
	{
		temp+='#';
		string cur=s+temp+'.';
		generate(cur, len+1);
	}
}

int check(string s)
{
	stringstream ss(s);
	string store=s;
	string store2="";
	int num;
	char ch;
	set<int> cur;
	for(int i=1;i<=4;i++)
	{
		ss>>num;
		store2+=to_string(num);
		if(num>255)
			return false;
		if(i!=4)
		{
			ss>>ch;
			store2+='.';
		}
	}
	return (store==store2);
}

void generate2(string &s, int i, int j, int bitmask)
{
	if(i>j)
	{
		if(bitmask==to_have&&check(s))
			ans.push_back(s);
		return;
	}
	if(s[i]=='.')
		return generate2(s, i+1, j, bitmask);
	if(s[j]=='.')
		return generate2(s, i, j-1, bitmask);
	for(int k=0;k<=9;k++)
	{
		if(!have[k])
			continue;
		s[i]=s[j]=char(k+'0');
		generate2(s, i+1, j-1, bitmask|(1<<k));
	}
}

int32_t main()
{
    IOS;
   	cin>>n;
   	generate("", 1);
   	for(int i=1;i<=n;i++)
   	{
   		int k;
   		cin>>k;
   		have[k]=1;
   		to_have|=(1<<k);
   	}
   	for(auto it:types)
   	{
   		generate2(it, 0, it.size()-1, 0);
   	}
   	cout<<ans.size()<<endl;
   	for(auto it:ans)
   		cout<<it<<endl;
    return 0;
}