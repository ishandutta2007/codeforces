#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[7005],b[7005],out[7005],sum,size,pd[7005];
bitset <7002> k[65];
bool c[7005][7005];
int main()
{
	cin>>n,size=n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i],sum+=b[i];
	for(int i=0;i<60;i++){
		for(int j=1;j<=n;j++)
			if(!((a[j]>>i)&1))
				k[i][j]=1;
	}
	for(int i=1;i<=n;i++){
		bitset <7002> g;
		g.reset();
		for(int j=0;j<60;j++)
			if((a[i]>>j)&1)
				g=g|k[j];
		for(int j=1;j<=n;j++)
			if(g[j])
				c[i][j]=1,out[i]++;
	}
//	for(int i=1;i<=n;i++)
//		cout<<out[i]<<" ";
//	cout<<endl;
	while(size>1){
		queue <ll> del;
		for(int j=1;j<=n;j++)
			if(out[j]==size-1&&!pd[j])
				del.push(j),pd[j]=1;
		if(!del.size())cout<<sum,exit(0);
		while(del.size()){
			size--;
			int num=del.front();
			for(int j=1;j<=n;j++)
				if(!pd[j])
					out[j]-=c[j][num];
			out[num]=0;
			del.pop();
			sum-=b[num];
		}
	}
	cout<<0;
    return 0;
}