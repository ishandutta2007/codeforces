#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const int SQRTN = 450;

int n,x;
int p[N],d[N],id[N],val[N];
vector<int> g[N],posd[N],w[N];
bool f[SQRTN][N];
int k[SQRTN][N];
bool ans[N];

void dfs(int x){
	posd[d[x]].push_back(x);
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		d[y]=d[x]+1;
		dfs(y);
	}
}

bool cmp(int x,int y){
	return posd[x].size()<posd[y].size();
}

int main(){
	scanf("%d%d",&n,&x);
	for(int i=2;i<=n;++i){
		scanf("%d",&p[i]);
		g[p[i]].push_back(i);
	}
	d[1]=1;
	dfs(1);
	int cntd=*max_element(d+1,d+n+1);
	for(int i=1;i<=cntd;++i)id[i]=i;
	sort(id+1,id+cntd+1,cmp);
	int tot=0;
	for(int i=1,r=1;i<=cntd;i=++r){
		++tot;
		val[tot]=posd[id[i]].size();
		w[tot].push_back(id[i]);
		while(r+1<cntd&&posd[id[r+1]].size()==posd[id[i]].size()){
			w[tot].push_back(id[r+1]);
			++r;
		}
	}
	static int q[N];
	f[0][0]=1;
	for(int i=1;i<=tot;++i)
	for(int j=0;j<=x;++j){
		if(f[i-1][j])k[i][j]=0;
		else if(j>=val[i])k[i][j]=k[i][j-val[i]]+1;
		else k[i][j]=0;
		if(k[i][j]<=w[i].size())f[i][j]=f[i-1][j-k[i][j]*val[i]];
		else f[i][j]=0;
	}
	if(f[tot][x]){
		for(int i=tot;i>=1;--i){
			int c=k[i][x];
			x-=c*val[i];
			for(int j=0;j<c;++j){
				int d=w[i][j];
				for(int t=0;t<posd[d].size();++t){
					ans[posd[d][t]]=1;
				}
			}
		}
		printf("%d\n",cntd);
		for(int i=1;i<=n;++i){
			if(ans[i])putchar('a');
			else putchar('b');
		}
		printf("\n");
		return 0;
	}
	int a=x,b=n-x;
	for(int i=1;i<=cntd;++i){
		if(posd[i].size()<=a){
			for(int j=0;j<posd[i].size();++j){
				ans[posd[i][j]]=1;
			}
			a-=posd[i].size();
		}
		else if(posd[i].size()<=b){
			b-=posd[i].size();
		}
		else{
			static int q1[N],q2[N];
			for(int j=0;j<posd[i].size();++j){
				int x=posd[i][j];
				if(!g[x].size())q2[++q2[0]]=x;
				else q1[++q1[0]]=x;
			}
			if(a>b){
				for(int i=1;i<=q1[0];++i){
					ans[q1[i]]=1;
				}
				a-=q1[0];
				for(int i=1;i<=q2[0];++i){
					if(a){
						ans[q2[i]]=1;
						--a;
					}
					else{
						--b;
					}
				}
			}
			else{
				b-=q1[0];
				for(int i=1;i<=q2[0];++i){
					if(b){
						--b;
					}
					else{
						ans[q2[i]]=1;
						--a;
					}
				}
			}
		}
	}
	printf("%d\n",cntd+1);
	for(int i=1;i<=n;++i){
		if(ans[i])putchar('a');
		else putchar('b');
	}
	printf("\n");
	return 0;
}