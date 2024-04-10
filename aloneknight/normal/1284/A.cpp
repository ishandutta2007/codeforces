#include<bits/stdc++.h>
using namespace std;
int n,m,q;string S[25],T[25];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>S[i];
	for(int i=0;i<m;i++)cin>>T[i];
	cin>>q;
	while(q--)
	{
		int x;cin>>x;x--;
		cout<<S[x%n]<<T[x%m]<<endl;
	}
	return 0;
}