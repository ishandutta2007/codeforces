#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int> 
#define mp make_pair
int n,p,tt,a[100005][3],c[3];map<int,int>b;priority_queue<pii>Q;
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),b[x]++;
	for(auto t:b)Q.push(mp(t.Y,t.X));
	while(Q.size()>=3)
	{
		tt++;for(int i=0;i<3;i++){a[tt][i]=Q.top().Y;c[i]=Q.top().X-1;Q.pop();}
		for(int i=0;i<3;i++)if(c[i])Q.push(mp(c[i],a[tt][i]));
		sort(a[tt],a[tt]+3);
	}
	printf("%d\n",tt);
	for(int i=1;i<=tt;i++)printf("%d %d %d\n",a[i][2],a[i][1],a[i][0]);
	return 0;
}