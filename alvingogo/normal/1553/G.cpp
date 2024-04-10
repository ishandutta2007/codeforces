#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

vector<int> bo,ss;
int find(int x){
	return bo[x]==x?x:bo[x]=find(bo[x]);
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
int main(){
	AquA;
	const int m=1e6+2;
	vector<int> vis(m),pr,pt(m),lf(m);
	for(int i=2;i<=m;i++){
		if(vis[i]==0){
			pr.push_back(i);
			pt[i]=pr.size()-1;
			lf[i]=i;
		}
		for(auto h:pr){
			if(h*i>=m){
				break;
			}
			vis[h*i]=1;
			lf[h*i]=lf[h];
			if(h%i==0){
				break;
			}
		}
	}
	vector<set<int> > at(pr.size());
	auto get=[&](int x){
		vector<int> k;
		while(x!=1){
			k.push_back(lf[x]);
			x/=lf[x];
		}
		sort(k.begin(),k.end());
		k.erase(unique(k.begin(),k.end()),k.end());
		return k;
	};
	bo.resize(pr.size());
	ss.resize(pr.size(),1);
	iota(bo.begin(),bo.end(),0);
	int n,q;
	cin >> n >> q;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
		auto h=get(v[i]);
		for(auto a:h){
			for(auto b:h){
				merge(pt[a],pt[b]);
			}
		}
	}
	for(int i=0;i<n;i++){
		auto h=get(v[i]),u=get(v[i]+1);
		for(auto a:u){
			a=find(pt[a]);
			for(auto b:u){
				b=find(pt[b]);
				if(a!=b){
					at[a].insert(b);
				}
			}
		}
		for(auto a:u){
			a=find(pt[a]);
			for(auto b:h){
				b=find(pt[b]);
				at[a].insert(b);
				at[b].insert(a);
			}
		}
	}
	for(int i=0;i<q;i++){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		auto h=get(v[a]),u=get(v[b]);
		int y=find(pt[h[0]]),z=find(pt[u[0]]);
		if(y==z){
			cout << 0 << "\n";
		}
		else if(at[y].find(z)!=at[y].end()){
			cout << 1 << "\n";
		}
		else{
			cout << 2 << "\n";
		}
	}
	return 0;
}