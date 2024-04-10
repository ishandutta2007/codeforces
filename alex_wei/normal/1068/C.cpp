#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005];
vector <pair<int,int> >c[5005];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		c[x].push_back(make_pair((x-1)*5000+(++a[x]),(y-1)*5000+(++a[y]))); 
	}
	for(int i=1;i<=n;i++){
		cout<<1+max(0,a[i]-1)*2+c[i].size()<<endl;
		cout<<(i-1)*5000+1<<" "<<(i-1)*5000+1<<endl;
		for(int j=2;j<=a[i];j++)
			cout<<(i-1)*5000+j<<" "<<(i-1)*5000+j<<endl<<(i-1)*5000+j<<" "<<(i-1)*5000+j-1<<endl;
		for(int j=0;j<c[i].size();j++)
			cout<<c[i][j].first<<" "<<c[i][j].second<<endl;
	}
	return 0;
}