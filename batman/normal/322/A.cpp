#include <bits/stdc++.h>
using namespace std;
int n,m;
bool mark[2][111];
vector <pair <int,int> > p;
int main()
{ 
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!mark[0][i] || !mark[1][j])
			{
				p.push_back({i,j});
				mark[0][i]=mark[1][j]=true;
			}
	cout<<p.size()<<endl;
	for(int i=0;i<p.size();i++)
		cout<<p[i].first<<" "<<p[i].second<<endl;		
    return 0;
}