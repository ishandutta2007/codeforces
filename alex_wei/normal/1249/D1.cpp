#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+2;
struct seg{
	int l,r,id;
	bool operator < (const seg &v) const {
		return r<v.r;
	}
}g[N];
bool cmp(seg a,seg b){return a.l<b.l;}
int n,k,p[N],st[N<<2],laz[N<<2];
priority_queue <seg> q;
vector <int> c;
void modify(int l,int r,int ml,int mr,int x,int w)
{
	if(ml<=l&&r<=mr){laz[x]+=w,st[x]+=w;return;}
	int m=l+r>>1;
	if(ml<=m)modify(l,m,ml,mr,x<<1,w);
	if(m<mr)modify(m+1,r,ml,mr,x<<1|1,w);
}
void push(int l,int r,int x)
{
	laz[x<<1]+=laz[x];
	laz[x<<1|1]+=laz[x];
	st[x<<1]+=laz[x];
	st[x<<1|1]+=laz[x];
	laz[x]=0;
}
int query(int l,int r,int pos,int x)
{
	if(l==r)return st[x];
	push(l,r,x);
	int m=l+r>>1;
	if(pos<=m)return query(l,m,pos,x<<1);
	else return query(m+1,r,pos,x<<1|1);
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>g[i].l>>g[i].r,g[i].id=i;
    	modify(1,N-2,g[i].l,g[i].r,1,1);
    }
    sort(g+1,g+n+1,cmp);
    int pos=1;
    for(int i=1;i<=N-2;i++){
    	while(pos<=n&&g[pos].l==i)q.push(g[pos++]);
    	while(query(1,N-2,i,1)>k){
//    		cout<<query(1,N-2,i,1)<<endl;
    		seg t=q.top();
    		q.pop();
    		c.push_back(t.id);
    		modify(1,N-2,t.l,t.r,1,-1);
		}
	}
	cout<<c.size()<<endl;
	for(int i=0;i<c.size();i++)
		cout<<c[i]<<" ";
	return 0;
}