#include<bits/stdc++.h>
using namespace std;
struct node{
	int good;
	char score[102];
}c[102];
int n,m,ans;
char mas[102];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i].score[j],mas[j]=max(mas[j],c[i].score[j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(c[i].score[j]==mas[j])
				c[i].good=1;
	for(int i=0;i<n;i++)
		ans+=c[i].good;
	cout<<ans;
	return 0;
}