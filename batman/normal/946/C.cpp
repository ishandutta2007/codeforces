#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)501*1000)

string s;
ll now;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	for(int i=0;now<26 && i<s.size();i++)
		if((s[i]-'a')<=now)
			s[i]=(char)(now+'a'),now++;
	if(now!=26)return cout<<"-1\n",0;
	cout<<s<<"\n";
	return 0;
}