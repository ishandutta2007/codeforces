#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,t1,t2,k;
struct node{
	int id,t;
}p[1005];
bool cmp(node a,node b){return a.t>b.t||a.t==b.t&&a.id<b.id;}
int main()
{
	cin>>n>>t1>>t2>>k;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		p[i].id=i;
		p[i].t=max(a*t1*(100-k)+b*t2*100,b*t1*(100-k)+a*t2*100);
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
		printf("%d %.2lf\n",p[i].id,p[i].t/100.0);
    return 0;
}