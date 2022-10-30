#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define N 100100
#define M 300
using namespace std;
int f[N],ans[N];
pair<int,int> q[N];
vector<pair<int,int> > col[N],total;
unordered_map<long long,int> light;
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y){
	if(find(x)==find(y)) return;
	f[find(x)]=find(y);
}
int main(){
	int n,m,a,b,c,i,j,k,l; 
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		col[c].push_back(make_pair(a,b));
	}
	scanf("%d",&k);
	for(i=0;i<k;i++){
		scanf("%d%d",&q[i].first,&q[i].second);
		if(q[i].first>q[i].second) swap(q[i].first,q[i].second);
		light[1LL*q[i].first*N+q[i].second]=0;
	}
	for(i=1;i<=m;i++){
		if(col[i].size()<M){
			vector<int> vertex;
			for(j=0;j<col[i].size();j++){
				vertex.push_back(col[i][j].first);
				vertex.push_back(col[i][j].second);
			}
			sort(vertex.begin(),vertex.end());
			vertex.resize(unique(vertex.begin(),vertex.end())-vertex.begin());
			for(j=0;j<vertex.size();j++){
				f[vertex[j]]=vertex[j];
			}
			for(j=0;j<col[i].size();j++){
				uni(col[i][j].first,col[i][j].second);
			}
			for(j=0;j<vertex.size();j++){
				for(l=j+1;l<vertex.size();l++){
					if(find(vertex[j])!=find(vertex[l])) continue;
					if(light.count(1LL*vertex[j]*N+vertex[l])){
						light[1LL*vertex[j]*N+vertex[l]]++;
					}
				}
			}
		}
		else{
			for(j=1;j<=n;j++) f[j]=j;
			for(j=0;j<col[i].size();j++){
				uni(col[i][j].first,col[i][j].second);
			}
			for(j=0;j<k;j++){
				if(find(q[j].first)==find(q[j].second)) ans[j]++;
			}
		}
	}
	for(i=0;i<k;i++){
		printf("%d\n",light[1LL*q[i].first*N+q[i].second]+ans[i]);
	}
	return 0;
}