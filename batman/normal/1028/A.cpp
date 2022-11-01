#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)501)

int n,m;
string s[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='W')continue;
			int k=1;
			while(j+k<m && s[i][j+k]=='B')k++;
			cout<<i+k/2+1<<" "<<j+k/2+1<<"\n";
			return 0;
		}
	
	return 0;
}