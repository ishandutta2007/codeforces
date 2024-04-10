#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,a[200005],mx[200005];
struct node{
	int p,s;
}c[200005];
bool cmp(node a,node b){return a.p<b.p;}
int find(int l,int r,int val)
{
	if(l==r)return l;
	int m=l+r>>1;
	if(c[m].p<val)return find(m+1,r,val);
	else return find(l,m,val);
}
int main()
{
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cin>>m;
		for(int i=1;i<=m;i++)
			cin>>c[i].p>>c[i].s,mx[i]=0;
		sort(c+1,c+m+1,cmp);
		for(int i=m;i;i--)
			mx[i]=(i==m?c[i].s:max(mx[i+1],c[i].s));
		int pd=0,ans=0;
		for(int i=1;i<=n;i++){
			int las=i,mxx=0;
			while(las<=n){
				mxx=max(mxx,a[las]);
				if(mxx>c[m].p){pd=1;break;}
				int pos=find(1,m,mxx);
				if(mx[pos]<las-i+1)break;
				las++;
			}
			if(pd)break;
			las--;
			i=las;
			ans++;
		}
		if(pd)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
    return 0;
}
/*
2
6
2 3 11 14 1 8
2
3 2
100 1
6
30 71 10 72 22 3
3
30 1
100 1
70 2
*/