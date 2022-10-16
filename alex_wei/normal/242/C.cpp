#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct pos{
	ll x,y,val,st;
};
queue <pos> q;
map <ll,bool> mp;
ll a,b,c,d,n,aim;
ll get(ll x,ll y){return x*1e9+y;}
int main()
{
	cin>>a>>b>>c>>d>>n,aim=get(c,d);
	if(c-a>n)cout<<-1,exit(0);
	for(int i=0;i<n;i++){
		ll w,l,r;
		cin>>w>>l>>r;
		for(ll j=l;j<=r;j++)
			mp[get(w,j)]=1;
	}
	q.push((pos){a,b,get(a,b),0}),mp[get(a,b)]=0;
	while(q.size()){
		pos t=q.front();
		q.pop();
		if(t.val==aim)cout<<t.st,exit(0);
		for(int i=-1;i<2;i++)
			for(int j=-1;j<2;j++)
				if(i!=0||j!=0){
					ll xx=t.x+i,yy=t.y+j,k=get(xx,yy);
					if(xx>0&&yy>0&&xx<=1e9&&yy<=1e9&&mp[k])
						mp[k]=0,q.push((pos){xx,yy,k,t.st+1});
				}
	}
	cout<<-1;
	return 0;
}