#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int a,b;
}c[100005];
bool cmp(node a,node b){return a.a>b.a;}
int n,a[100005],b[100005],lef,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],c[a[i]].a=n-i+1;
	for(int i=1;i<=n;i++)
		cin>>b[i],c[b[i]].b=n*2-i+1;
	sort(c+1,c+n+1,cmp);
	lef=c[1].b;
	for(int i=2;i<=n;i++){
		if(c[i].b>lef)ans++;
		lef=min(lef,c[i].b);
	}
	cout<<ans;
    return 0;
}