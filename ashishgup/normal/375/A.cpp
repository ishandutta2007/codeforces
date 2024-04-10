#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

string store[7];
vector<int> v;

int32_t main()
{
    IOS;
   	v.push_back(1);
   	v.push_back(6);
   	v.push_back(8);
   	v.push_back(9);
   	do
   	{
   		string str="";
   		int cur=0;
   		for(auto it:v)
   		{
   			str+=(it+'0');
   			cur*=10;
   			cur+=it;
   		}
   		int rem=cur%7;
   		store[rem]=str;
   	}
   	while(next_permutation(v.begin(), v.end()));
   	string s;
   	cin>>s;
   	map<char, int> m;
   	for(auto it:s)
   		m[it]++;
   	m['1']--;
   	m['6']--;
   	m['8']--;
   	m['9']--;
   	string ans="";
   	int rem=0;
   	for(auto it:m)
   	{
   		if(it.first=='0')
   			continue;
   		for(int i=1;i<=it.second;i++)
   		{
   			ans+=it.first;
   			rem*=10;
   			rem+=(it.first-'0');
   			rem%=7;
   		}
   	}
   	rem*=10000;
   	rem%=7;
   	ans+=(store[(7-rem)%7]);
   	for(int i=1;i<=m['0'];i++)
   	{
   		ans+='0';
   	}
   	cout<<ans<<endl;
    return 0;
}