#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)101*1000)

ll x1,y1,r1,R1,x2,y2,r2,R2,ans;
ld dis;
bool mark[4];

bool out(ll r,ll rr)
{
	return r+rr<=dis;
}

bool in(ll r,ll rr)
{
	if(max(r,rr)<=dis)return 0;
	if(rr>=dis+r)return 1;
	return 0;
}

bool check(ll r,ll rr)
{
	if(r+rr<=dis)return 0;
	if(max(r,rr)<=dis && r+rr>dis)return 1;
	if(r>rr)swap(r,rr);
	if(rr<dis+r)return 1;
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>x1>>y1>>r1>>R1;
	cin>>x2>>y2>>r2>>R2;
	dis=sqrt((ld)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if(check(r1,r2))mark[0]=mark[2]=1;
	if(check(R1,r2))mark[1]=mark[2]=1;
	if(check(r1,R2))mark[0]=mark[3]=1;
	if(check(R1,R2))mark[1]=mark[3]=1;
	
	if(in(r2,r1) && in(r1,R2))mark[0]=1;
	if(in(r2,R1) && in(R1,R2))mark[1]=1;
	if(in(r1,r2) && in(r2,R1))mark[2]=1;
	if(in(r1,R2) && in(R2,R1))mark[3]=1;
	
	if(out(r2,r1) && in(r1,R2))mark[0]=1;
	if(out(r2,R1) && in(R1,R2))mark[1]=1;
	if(out(r1,r2) && in(r2,R1))mark[2]=1;
	if(out(r1,R2) && in(R2,R1))mark[3]=1;
	for(int i=0;i<4;i++)ans+=!mark[i];
	cout<<ans;
	return 0;
}