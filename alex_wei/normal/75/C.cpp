#include<bits/stdc++.h>
using namespace std;
int a,b,n,x,y,d;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
vector <int> p;
int main()
{
	cin>>a>>b>>n,d=gcd(a,b);
	for(int i=1;i<=sqrt(d);i++)
		if(d%i==0)
			p.push_back(i);
	for(int i=sqrt(d);i>0;i--)
		if(d%i==0&&i*i!=d)
			p.push_back(d/i);
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		int ans=-1;
		for(int j=0;j<p.size();j++)
			if(x<=p[j]&&p[j]<=y)
				ans=max(ans,p[j]);
		cout<<ans<<endl;
	}
	return 0;
}