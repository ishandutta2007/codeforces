#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{ll a,b;}c[22];
bool cmp(node a,node b){return a.b>b.b;}
ll n,m,ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>c[i].a>>c[i].b;
	sort(c+1,c+m+1,cmp);
	for(int i=1;i<=m&&n;i++){
		int res=min(n,c[i].a);
		ans+=res*c[i].b,n-=res;
	}
	cout<<ans;
    return 0;
}