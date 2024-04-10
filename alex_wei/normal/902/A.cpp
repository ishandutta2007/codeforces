#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}c[102];
bool cmp(node a,node b){return a.l<b.l;}
int n,m,p[102];
int main()
{
	cin>>n>>m;
	p[0]=1;
	for(int i=0;i<n;i++)
		cin>>c[i].l>>c[i].r;
	for(int i=0;i<m;i++)
		if(p[i])
			for(int j=0;j<n;j++)
				if(c[j].l<=i&&i<=c[j].r)
					for(int k=c[j].l;k<=c[j].r;k++)
						p[k]=1;
	if(p[m])cout<<"YES";
	else cout<<"NO";
	return 0;
}