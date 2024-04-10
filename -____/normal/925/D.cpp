//CF 966D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 333333;
const int inf = 1e9;
int n,m,d[N],f[N],s[N],b[N];
vector<int> v[N];
queue<int> q;
void bfs(int u){
	int i,x,y;
	d[u]=0;
	q.push(u);
	while(!q.empty()){
		x=q.front();
		q.pop();
		i=v[x].size();
		while(i--){
			y=v[x][i];
			if(d[y]>=inf){
				d[y]=d[x]+1;
				f[y]=x;
				q.push(y);
			}
		}
	}
}
int main()
{
	int i,j,k,x,y,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		if(y>1)
			v[x].push_back(y),s[x]++;
		if(x>1)
			v[y].push_back(x),s[y]++;
	}
	for(i=1;i<=n;i=i+1)
		d[i]=inf,f[i]=0;
	bfs(1);
	ans=d[n];
	if(ans>4){
		for(i=1;i<=n;i=i+1)
			if(d[i]==2)
				break;
		if(i<=n){
			cout<<4<<endl<<1<<' '<<f[i]<<' '<<i<<' '<<1<<' '<<n;
			return 0;
		}
	}
	if(ans>5){
		for(i=1;i<=n;i=i+1)
			d[i]=inf,f[i]=0;
		i=v[1].size();
		while(i--){
			x=v[1][i];
			if(d[x]>=inf)
				bfs(x);
		}
		for(i=1;i<=n;i=i+1)
			if(d[i]==2)
				break;
		if(i<=n){
			cout<<5<<endl<<1<<' '<<i<<' '<<f[i]<<' '<<f[f[i]]<<' '<<i<<' '<<n;
			return 0;
		}
		i=v[1].size();
		while(i--){
			x=v[1][i];
			if(d[x])
				continue;
			j=v[x].size();
			while(j--){
				y=v[x][j];
				k=v[y].size();
				while(k--){
					b[v[y][k]]=1;
				}
				b[y]=1;
				k=v[x].size();
				while(k--){
					if(!b[v[x][k]]){
						cout<<5<<endl<<1<<' '<<y<<' '<<x<<' '<<v[x][k]<<' '<<y<<' '<<n;
						return 0;
					}
					b[v[x][k]]=0;
				}
			}
		}
	}
	if(ans==inf){
		cout<<-1;
		return 0;
	}
	for(i=n;i;i=f[i])
		v[0].push_back(i);
	i=v[0].size();
	cout<<i-1<<endl;
	while(i--){
		cout<<v[0][i]<<' ';
	}
	return 0;
}