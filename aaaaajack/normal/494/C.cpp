#include<cstdio>
#include<vector>
#include<algorithm>
#include<deque>
#define N 5100
#define M 100100
using namespace std;
struct node{
	int l;
	int r;
	double p;
}v[N];
vector<int> g[N];
deque<int> mv[N];
deque<double> pv[N];
int a[M];
bool used[N];
bool cmp(int i,int j){
	return v[i].r<v[j].l;
}
inline bool inv(int i,int j){
	if(v[i].l==v[j].l&&v[i].r==v[j].r) return i>j;
	return v[i].r<=v[j].r&&v[i].l>=v[j].l;
}
void merge(int a,int b,deque<int>& nm,deque<double>& np){
	int i=0,j=0;
	double pa=0,pb=0;
	while(i<mv[a].size()&&j<mv[b].size()){
		while(i<mv[a].size()&&mv[a][i]<mv[b][j]){
			i++;
			pa+=pv[a][i-1];
		}
		if(i==mv[a].size()) break;
		while(j<mv[b].size()&&mv[b][j]<mv[a][i]){
			j++;
			pb+=pv[b][j-1];
		}
		if(j==mv[b].size()) break;
		nm.push_back(mv[a][i]);
		np.push_back(pv[a][i]*pv[b][j]+pv[a][i]*pb+pv[b][j]*pa);
		i++;
		pa+=pv[a][i-1];
		j++;
		pb+=pv[b][j-1];
	}
	while(i<mv[a].size()){
		nm.push_back(mv[a][i]);
		np.push_back(pv[a][i]);
		i++;
	}
	while(j<mv[b].size()){
		nm.push_back(mv[b][j]);
		np.push_back(pv[b][j]);
		j++;
	}
}
void go(int t){
	int i,j=0,k;
	deque<int> nm;
	deque<double> np;
	for(i=v[t].l;i<=v[t].r;i++){
		if(j<g[t].size()&&i==v[g[t][j]].l){
			k=g[t][j];
			go(k);
			nm.clear();
			np.clear();
			merge(t,k,nm,np);
			mv[t]=nm;
			pv[t]=np;
			i=v[k].r;
			j++;
		}
		else{
			if(mv[t].empty()||a[i]>mv[t].back()){
				mv[t].clear();
				pv[t].clear();
				mv[t].push_back(a[i]);
				pv[t].push_back(1);
			}
			else{
				while(mv[t].front()<a[i]){
					mv[t].pop_front();
					pv[t][1]+=pv[t][0];
					pv[t].pop_front();
				}
			}
		}
	}
	pv[t].push_back(v[t].p*pv[t].back());
	mv[t].push_back(mv[t].back()+1);
	for(i=pv[t].size()-2;i>=0;i--){
		pv[t][i]=pv[t][i]*(1-v[t].p)+(i?pv[t][i-1]:0)*v[t].p;
	}
	//printf("%d.size=%d\n",t,pv[t].size());
}
			
int main(){
	int n,q,i,j,k;
	scanf("%d%d",&n,&q);
	v[0].l=1;
	v[0].r=n;
	v[0].p=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=q;i++){
		scanf("%d%d%lf",&v[i].l,&v[i].r,&v[i].p);
	}
	for(i=1;i<=q;i++){
		k=0;
		for(j=1;j<=q;j++){
			if(j==i) continue;
			if(inv(i,j)&&inv(j,k)){
				k=j;
			}
		}
		g[k].push_back(i);
		//printf("parent of %d: %d\n",i,k);
	}
	for(i=0;i<=q;i++) sort(g[i].begin(),g[i].end(),cmp);
	go(0);
	double ans=0;
	//for(j=0;j<=q;j++){
		//printf("node %d\n",j);
		for(i=0;i<pv[0].size();i++){
			//printf("%d %f\n",mv[j][i],pv[j][i]);
			ans+=mv[0][i]*pv[0][i];
		}
	//}
	printf("%.8f\n",ans);
	return 0;
}