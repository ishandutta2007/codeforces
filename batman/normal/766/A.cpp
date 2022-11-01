#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

string s,t;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s>>t;
	if(s==t)return cout<<-1,0;
	cout<<max((ll)s.size(),(ll)t.size());
	return 0;
}