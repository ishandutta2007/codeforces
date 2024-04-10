#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,h,p[1000005],pos=1,x,y;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d",&h),p[h]=1;
	for(int i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		if(p[pos])cout<<pos,exit(0);
		if(pos==x)swap(pos,y);
		else if(pos==y)swap(pos,x); 
	}
	cout<<pos;
    return 0;
}