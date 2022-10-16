#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,x;
}a[100002];
bool cmp(node a,node b){return a.num<b.num;}
map <int,int> l,r;
int n,s,sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].num,a[i].x=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(a[i].num!=a[i-1].num)
			l[a[i].num]=i,r[a[i-1].num]=i-1;
	r[a[n].num]=n;
	for(int i=1;i<=n;i++)
		if(l[a[i].num]>a[i].x||a[i].x>r[a[i].num])
			sum++;
	if(sum>2)cout<<"NO";
	else cout<<"YES";
    return 0;
}