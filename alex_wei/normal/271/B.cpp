#include<bits/stdc++.h>
using namespace std;
int p[520520],n,m,a,h[520],s[520],ans=1e9; 
int main()
{
	p[1]=1;
	for(int i=2;i<=500000;i++)
		if(!p[i])
			for(int j=i+i;j<=500000;j+=i)
				p[j]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a;
			while(p[a])a++,h[i]++,s[j]++;
		}
	for(int i=1;i<=n;i++)ans=min(ans,h[i]);
	for(int i=1;i<=m;i++)ans=min(ans,s[i]);
	cout<<ans;
    return 0;
}