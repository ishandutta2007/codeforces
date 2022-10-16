#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(3)
const int N=5e5+2;
set <int> d;
int n,m,cnt,vis[N],p;
vector <int> ans[N],c[N];
bool cmp(vector <int> a,vector <int> b){return a.size()<b.size();}
int read()
{
	int x=0;char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return x;
}
void print(int x)
{
	if(x<10)putchar(x^'0');
	else print(x/10),putchar((x%10)^'0');
}
int main()
{
//	freopen("t.txt","r",stdin);
//	freopen("p.txt","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int a,b;
		a=read(),b=read();
		c[a].push_back(b);
		c[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		d.insert(i);
	for(int i=1;i<=n;i++)
		if(vis[i]!=1e9){
			vis[i]=1e9;
			d.erase(i);
			queue <int> q;
			q.push(i);
			while(q.size()){
				int id=q.front();
				p++;
				for(int j=0;j<c[id].size();j++)
					if(vis[c[id][j]]!=1e9)
						vis[c[id][j]]=p;
				q.pop();
				ans[cnt].push_back(id);
				for(set <int>::iterator it=d.begin();it!=d.end();){
					int to=*it;
					if(vis[to]<p)
						vis[to]=1e9,q.push(to),d.erase(it++);
					else it++;
				}
			}
			cnt++;
		}
	print(cnt);puts("");
	sort(ans,ans+cnt,cmp);
	for(int i=0;i<cnt;i++){
		int k=ans[i].size();
		print(k),putchar(' ');
		for(int j=0;j<k;j++)
			print(ans[i][j]),putchar(' ');
		puts("");
	}
    return 0;
}