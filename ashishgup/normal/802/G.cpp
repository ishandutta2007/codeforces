#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main()
{
	string s;
	cin>>s;	
	string a="heidi";
	int ind=0;
	int n=s.size();
	for(int i=0;i<n;i++)
	{	
		if(s[i]==a[ind])
		{
			ind++;
		}
		if(ind==5)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}