#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,c[150],p[400005],q[400005],cnt;
string a,b;
deque <int> x,y;
int main()
{
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
		c[a[i]]++,c[b[i]]++;
	for(int i=0;i<128;i++)
		if(c[i]%2)cout<<-1,exit(0);
	for(int i=0;i<n;i++)
		if(a[i]!=b[i]){
			if(a[i]=='a')x.push_back(i+1);
			else y.push_back(i+1);
		}
	while(x.size()>1)
		p[++cnt]=x.front(),x.pop_front(),q[cnt]=x.front(),x.pop_front();
	while(y.size()>1)
		p[++cnt]=y.front(),y.pop_front(),q[cnt]=y.front(),y.pop_front();
	while(x.size()&&y.size())
		p[++cnt]=x.front(),q[cnt]=x.front(),p[++cnt]=x.front(),x.pop_front(),q[cnt]=y.front(),y.pop_front();
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<p[i]<<" "<<q[i]<<endl;
    return 0;
}