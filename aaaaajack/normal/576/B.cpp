#include<cstdio>
#include<vector>
#include<cstring>
#define N 100100
using namespace std;
vector<int> cyc[N];
vector<int> l,r;
int p[N],m,sz[N],id[N];
bool vis[N];
void add(int x,int y){
	for(int i=0;i<cyc[y].size();i++){
		l.push_back(cyc[x][i%cyc[x].size()]);
		r.push_back(cyc[y][i]);
	}
}
int main(){
	memset(id,-1,sizeof(id));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			for(int j=i;!vis[j];j=p[j]){
				vis[j]=true;
				cyc[m].push_back(j);
			}
			m++;
		}
	}
	for(int i=0;i<m;i++){
		if(id[cyc[i].size()]==-1) id[cyc[i].size()]=i;
	}
	if(id[1]==-1&&id[2]==-1) puts("NO");
	else{
		bool wrong=false;
		int root,rsz;
		if(id[1]==-1){
			root=id[2];
			l.push_back(cyc[root][0]);
			r.push_back(cyc[root][1]);
			rsz=2;
		}
		else root=id[1],rsz=1;
		for(int i=0;i<m;i++){
			if(i==root) continue;
			if(cyc[i].size()%rsz){
				wrong=true;
				break;
			}
			add(root,i);
		}
		if(wrong) puts("NO");
		else{
			puts("YES");
			for(int i=0;i<l.size();i++){
				printf("%d %d\n",l[i],r[i]);
			}
		}
	}
	return 0;
}