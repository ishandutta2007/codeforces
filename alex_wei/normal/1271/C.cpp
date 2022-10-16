#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,sx,sy,x[N],y[N],nx,ny,ans,ax,ay,cnt;
void calc(){
	cnt=0;
	for(int i=1;i<=n;i++)
		if((sx<=nx&&nx<=x[i]||x[i]<=nx&&nx<=sx)&&(sy<=ny&&ny<=y[i]||y[i]<=ny&&ny<=sy))
			cnt++;
}
int main(){
	cin>>n>>sx>>sy;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	nx=sx+1,ny=sy;
	calc();
	if(cnt>=ans)ans=cnt,ax=nx,ay=ny;
	nx=sx-1,ny=sy;
	calc();
	if(cnt>=ans)ans=cnt,ax=nx,ay=ny;
	nx=sx,ny=sy+1;
	calc();
	if(cnt>=ans)ans=cnt,ax=nx,ay=ny;
	nx=sx,ny=sy-1;
	calc();
	if(cnt>=ans)ans=cnt,ax=nx,ay=ny;
	cout<<ans<<endl<<ax<<" "<<ay<<endl;
    return 0;
}