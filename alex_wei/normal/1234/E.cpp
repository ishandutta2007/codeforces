#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+2;
ll n,m,x[N],cf[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>x[i];
	for(int i=1;i<m;i++){
		if(x[i]==x[i+1])continue;
		int u=x[i],v=x[i+1],dis=abs(u-v);
		if(u>v)swap(u,v);
		//i<u
		cf[1]+=dis;
		cf[u]-=dis;
		//i==u
		cf[u]+=v-1;
		cf[u+1]-=v-1;
		//u<i<v
		cf[u+1]+=dis-1;
		cf[v]-=dis-1;
		//i==v
		cf[v]+=u;
		cf[v+1]-=u;
		//v<i
		cf[v+1]+=dis;
	}
	for(int i=1;i<=n;i++)
		cf[i]+=cf[i-1],cout<<cf[i]<<" ";
    return 0;
}