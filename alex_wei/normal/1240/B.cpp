#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct query{
	int l,r,num;
}c[300005];
ll q,n,a[300005],cnt,pd[300005];
bool cmp(query a,query b){return a.num<b.num;}
int main()
{
	cin>>q;
	for(int l=0;l<q;l++){
		cin>>n;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(!pd[a[i]])
				pd[a[i]]=++cnt,c[cnt].l=c[cnt].r=i,c[cnt].num=a[i];
			c[pd[a[i]]].r=i;
		}
		sort(c+1,c+cnt+1,cmp);
		ll tmp=0,ans=cnt;
		for(int i=1;i<=cnt;i++){
			if(i==1||c[i-1].r<c[i].l)tmp++;
			else ans=min(ans,cnt-tmp),tmp=1;
		}
		cout<<min(ans,cnt-tmp)<<endl;
		for(int i=1;i<=n;i++)
			pd[i]=0;
	}
    return 0;
}
/*
2
5
5 1 2 3 4
5
5 3 1 2 4
*/