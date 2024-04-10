#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct pos{
	int h,id,t;
};
queue <pos> q;
int n,k,pd[100005][2];
string l,r;
int main()
{
	cin>>n>>k>>l>>r;
	for(int i=1;i<=n;i++){
		if(l[i-1]=='X')pd[i][0]=1;
		if(r[i-1]=='X')pd[i][1]=1;
	}
	q.push((pos){1,0,0}),pd[1][0]=1;
	while(!q.empty()){
		pos t=q.front(),nw;q.pop();
		nw=t;nw.h--;nw.t++;
		if(nw.h>0&&!pd[nw.h][nw.id]&&nw.h>nw.t)
			pd[nw.h][nw.id]=1,q.push(nw);
		nw=t;nw.h++;nw.t++;
		if(nw.h>n)cout<<"YES",exit(0);
		if(!pd[nw.h][nw.id]&&nw.h>nw.t)
			pd[nw.h][nw.id]=1,q.push(nw);
		nw=t;nw.h+=k;nw.id=!nw.id;nw.t++;
		if(nw.h>n)cout<<"YES",exit(0);
		if(!pd[nw.h][nw.id]&&nw.h>nw.t)
			pd[nw.h][nw.id]=1,q.push(nw);
	}
	cout<<"NO";
	return 0;
}