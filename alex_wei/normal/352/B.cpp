#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a,cnt,p[100005],x[100005];
vector <int> q[100005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a,q[a].push_back(i);
	for(int i=1;i<=1e5;i++)
		if(q[i].size()){
			int d=q[i].size()>1?q[i][1]-q[i][0]:0,pd=1;
			for(int j=2;j<q[i].size();j++)
				if(q[i][j]-q[i][j-1]!=d)
					pd=0;
			if(pd)cnt++,p[cnt]=d,x[cnt]=i;
		}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<x[i]<<" "<<p[i]<<endl;
	return 0;
}