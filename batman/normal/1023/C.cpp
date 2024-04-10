#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)501*1000)

int n,k;
string s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k>>s;
	int cnt=0,cnt2=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(' && cnt<k/2)cout<<s[i],cnt++;
		if(s[i]==')' && cnt2<cnt)cout<<s[i],cnt2++;
	}
	cout<<"\n";
	return 0;
}