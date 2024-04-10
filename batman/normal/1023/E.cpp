#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)2010)

int n;
pair <int,int> path[N];

int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	path[0]={1,1};
	for(int i=1;i<=n-1;i++)
	{
		path[i]=path[i-1];
		cout<<"? "<<path[i-1].first+1<<" "<<path[i-1].second<<" "<<n<<" "<<n<<endl;
		string s;cin>>s;
		if(s=="YES")path[i].first++;
		else path[i].second++;
	}
	path[2*n-2]={n,n};
	for(int i=2*n-3;i>=n;i--)
	{
		path[i]=path[i+1];
		cout<<"? "<<path[i-(n-1)].first<<" "<<path[i-(n-1)].second<<" "<<path[i+1].first<<" "<<path[i+1].second-1<<endl;
		string s;cin>>s;
		if(s=="YES")path[i].second--;
		else path[i].first--;
	}
	if(abs(path[n-1].first-path[n].first)+abs(path[n-1].second-path[n].second)>1)
	{
		cout<<0/0;
	}
	string ans="";
	for(int i=1;i<=2*n-2;i++)
	{
		if(path[i].first!=path[i-1].first)ans+='D';
		else ans+='R';
	}
	cout<<"! "<<ans<<endl;
	return 0;
}