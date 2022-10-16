#include<bits/stdc++.h>  
using namespace std;
#define ababa abababa
struct node{
	int x,y;
}c[1002];
bool cmp(node a,node b){return a.x<b.x;}
int n,s;
int main()
{
	cin>>s>>n;
	for(int i=1;i<=n;i++)cin>>c[i].x>>c[i].y;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(s>c[i].x)s+=c[i].y;
		else cout<<"NO",exit(0);
	}
	cout<<"YES";
	return 0;
}