#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i);
#define ET cout << "\n";
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET}
using namespace std;

pair<double,double> data[200000]; 
const double eps=1e-9;

int main()
{jizz
	int i,n,T,topL,topR,flag=0;
	double ans=0;
	cin >> n >> T;
	for(i=0;i<n;++i)
		cin >> data[i].S;
	for(i=0;i<n;++i)
		cin >> data[i].F;
	sort(data,data+n);
	for(topR=0;topR<n;++topR)
		if(data[topR].F>T) break;
	topL=topR-1;
	while(topL>=0 && (int)data[topL].F==T) ans+=data[topL].S,topL--,flag=1;
	if(topL==-1 || topR==n)
		return cout << ans << "\n",0;
	for(i=0;i<=topL;++i)
		data[i].F=T-data[i].F;
	for(i=topR;i<=n;++i)
		data[i].F-=T;
	for(;topR<n;++topR)
	{
		while(topL>=0 && data[topL].S*data[topL].F<=data[topR].F*data[topR].S) 
			data[topR].S-=data[topL].S*data[topL].F/data[topR].F,ans+=data[topL].S*data[topL].F/data[topR].F+data[topL].S,topL--;
		if(topL>=0) data[topL].S-=data[topR].F*data[topR].S/data[topL].F,ans+=data[topR].S+data[topR].F*data[topR].S/data[topL].F;
		else break;
	}
	cout << fixed << setprecision(10) << ans << "\n";
}