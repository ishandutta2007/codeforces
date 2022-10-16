#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,t[1000002],v[1000002];
queue <int> q[4];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i],a+=t[i]==1,b+=t[i]==2,c+=t[i]==3,q[t[i]].push(i);
	cout<<min(a,min(b,c))<<endl;
	for(int i=1;i<=min(a,min(b,c));i++){
		for(int j=1;j<4;j++)
			cout<<q[j].front()<<" ",q[j].pop();
		cout<<endl;
	}
    return 0;
}