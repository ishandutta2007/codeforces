#include<bits/stdc++.h>
using namespace std;
struct node{
	int ap,pos;
}ne[105],po[105];
bool cmp(node a,node b){return a.pos<b.pos;}
bool cmp2(node a,node b){return a.pos>b.pos;}
int n,neg,pos,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,a;
		cin>>x>>a;
		if(x<0)ne[++neg].ap=a,ne[neg].pos=x;
		else po[++pos].ap=a,po[pos].pos=x;
	}
	sort(ne+1,ne+neg+1,cmp2);
	sort(po+1,po+pos+1,cmp);
	int mx=min(neg,pos);
	for(int i=1;i<=mx;i++)
		ans+=ne[i].ap+po[i].ap;
	cout<<ans+max(ne[mx+1].ap,po[mx+1].ap);
	return 0;
}