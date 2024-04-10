#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const long long inf=1e11+11;
vector<int> bg,sm;
struct DINIC{
	struct edge{
		int to;
		long long c;
		int r;
	};
	int sz,s,t;
	vector<vector<edge> > e;
	vector<int> lv,iz;
	void init(int nn){
		sz=nn;
		s=0;
		t=sz-1;
		e.resize(sz);
		lv.resize(sz);
		iz.resize(sz);
	}
	void add(int u,int v,long long c){
		e[u].push_back({v,c,e[v].size()});
		e[v].push_back({u,0,e[u].size()-1});
	}
	bool bfs(){
		fill(lv.begin(),lv.end(),-1);
		lv[s]=0;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int y=q.front();
			q.pop();
			for(auto k:e[y]){
				if(k.c>0 && lv[k.to]==-1){
					lv[k.to]=lv[y]+1;
					q.push(k.to);
				}
			}
		}
		return lv[t]!=-1;
	}
	long long dfs(int u,long long f){
		if(u==t){
			return f;
		}
		for(int &i=iz[u];i<e[u].size();i++){
			if(e[u][i].c>0 && lv[e[u][i].to]==lv[u]+1){
				long long d=dfs(e[u][i].to,min(e[u][i].c,f));
				if(d>0){
					e[u][i].c-=d;
					e[e[u][i].to][e[u][i].r].c+=d;
					return d;
				}
			}
		}
		return 0;
	}
	long long flow(){
		long long ans=0;
		while(bfs()){
			fill(iz.begin(),iz.end(),0);
			while(1){
				long long d=dfs(s,inf);
				if(d==0){
					break;
				}
				ans+=d;
			}
		}
		return ans;
	}
    vector<int> get(){
        vector<int> v;
        for(int i=1;i<=bg.size();i++){
            for(auto h:e[i]){
                if(h.to!=0 && h.c==0){
                    v.push_back(h.to);
                    cout << bg[i-1]+bg[i-1]+sm[h.to-bg.size()-1] << " " << bg[i-1]+sm[h.to-bg.size()-1] << "\n";
                }
            }
        }
        return v;
    }   
};
int main(){
	AquA;
    int n,m;
    cin >> n >> m;
    DINIC di;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a+a>=m){
            cout << -1 << "\n";
            return 0;
        }
        if(3ll*a<m){
            sm.push_back(a);
        }
        else{
            bg.push_back(a);
        }
    }
    di.init(n+2);
    int bs=bg.size(),ss=sm.size();
    for(int i=0;i<bs;i++){
        for(int j=0;j<ss;j++){
            if(bg[i]%sm[j]==0 && bg[i]+bg[i]+sm[j]<=m){
                di.add(i+1,j+1+bs,1);
            }
        }
    }
    for(int i=0;i<bs;i++){
        di.add(0,i+1,1);
    }
    for(int i=0;i<ss;i++){
        di.add(i+1+bs,n+1,1);
    }
    if(di.flow()<bs){
        cout << -1 << "\n";
        return 0;
    }
    cout << ss << "\n";
    auto f=di.get();
    
    vector<int> vis(ss);
    for(auto j:f){
        vis[j-bs-1]=1;
    }
    for(int i=0;i<ss;i++){
        if(!vis[i]){
            cout << 3*sm[i] << " " << 2*sm[i] << "\n";
        }
    }
	return 0;
}