#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,a[101000],tmp;
struct C{
	int b,p;
}c[101000];
ll ans=0,tot;

bool cmp(C c1,C c2){
	return c1.b<c2.b;
}

priority_queue<int,vector<int>,greater<int> >q;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&c[i].b);
	for (int i=1;i<=m;i++) scanf("%d",&c[i].p);
	sort(c+1,c+m+1,cmp);
	int p,pos=0;
	for (int now=n;now>0;now=p-1){
		p=now; tot=a[p];
		for (;a[p-1]<=a[now]&&p>1;) tot+=a[--p];
		for (;pos<m&&c[pos+1].b<=a[now];) q.push(c[++pos].p);
		for (;!q.empty();){
			if (tot>=q.top()){
				ans++;
				tot-=q.top();
				q.pop();
			}else{
				tmp=q.top()-tot;
				q.pop();
				q.push(tmp);
				tot=0;
				break;
			}
		}
	}
	cout<<ans;
}