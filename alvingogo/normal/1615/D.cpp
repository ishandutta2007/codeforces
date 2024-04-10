#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

vector<int> bo,ss;
int find(int g){
	if(bo[g]==g){
		return g;
	}
	return bo[g]=find(bo[g]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y){
		return;
	}
	if(ss[x]>ss[y]){
		swap(x,y);
	}
	bo[x]=y;
	ss[y]+=ss[x];
}
struct no{
	vector<pair<int,int> > ch;
	pair<int,int> fa;
	int x;
};
vector<no> vn;
vector<int> ff;
void dfs(int r,pair<int,int> f){
	//cout << r << " " << f.fs << " " << f.sc << endl;
	vn[r].fa=f;
	for(auto h:vn[r].ch){
		if(h.fs!=f.fs){
			dfs(h.fs,{r,h.sc});
		}
	}
	if(vn[r].fa.sc==-1){
		vn[r].fa.sc=ff[find(r)]^ff[find(vn[r].fa.fs)];	
	}
	if(r==vn[r].fa.fs){
		return;
	}
	cout << r+1 << " " << vn[r].fa.fs+1 << " " << vn[r].fa.sc << "\n";
}
int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vn.clear();
		ff.clear();
		bo.clear();
		ss.clear();
		vn.resize(n);
		int z=m;
		vector<pair<pair<int,int>,int> > vq; 
		for(int i=1;i<n;i++){
			int a,b,x;
			cin >> a >> b >> x;
			a--;
			b--;
			if(x>=0){
				z++;
				bitset<32> f=x;
				vq.push_back({{a,b},f.count()%2});
			}
			vn[a].ch.push_back({b,x});
			vn[b].ch.push_back({a,x});
		}
		for(int i=0;i<m;i++){
			int a,b,x;
			cin >> a >> b >> x;
			a--;
			b--;
			vq.push_back({{a,b},x});
		}
		bo.resize(2*n);
		ss.resize(2*n,1);
		for(int i=0;i<2*n;i++){
			bo[i]=i;
		}
		for(auto h:vq){
			if(h.sc==0){
				merge(h.fs.fs,h.fs.sc);
				merge(2*n-h.fs.fs-1,2*n-h.fs.sc-1);
			}
			else{
				merge(h.fs.fs,2*n-h.fs.sc-1);
				merge(2*n-h.fs.fs-1,h.fs.sc);
			}
		}
		ff.resize(2*n);
		vector<int> vis(2*n);
		int flag=0;
		for(int i=0;i<n;i++){
			if(find(i)==find(2*n-i-1)){
				flag=1;
			}
		}
		if(flag){
			cout << "NO" << "\n";
			continue;
		}
		int zz=0;
		for(int i=0;i<n;i++){
			int a=find(i),b=find(2*n-i-1);
			if(vis[b]){
				ff[a]=ff[b]^1;
			}
			else if(!vis[a]){
				ff[a]=0;
				zz=i;
				vis[a]=1;
				ff[b]=1;
				vis[b]=1;
			}
		}
		cout << "YES\n";
		dfs(zz,{zz,0});
	}
	return 0;
}