#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;
 
const long long inf=1e11+11;
struct DINIC{
	struct edge{
		int to;
		long long c;
		int r;
        int id;
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
	void add(int u,int v,long long c,int id){
		e[u].push_back({v,c,e[v].size(),id});
		e[v].push_back({u,0,e[u].size()-1,id});
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
    pair<set<int>,set<int> > get(int l){
        set<int> a,b;
        for(int i=1;i<=l;i++){
            for(auto h:e[i]){
                if(h.id==-1){
                    continue;
                }
                if(h.c==0){
                    a.insert(h.id);
                }
                else{
                    b.insert(h.id);
                }
            }   
        }
        return {a,b};
    } 
};
 
signed main(){
    int l,r,m,q;
    cin >> l >> r >> m >> q;
    int n=l+r;
    auto idx=[&](int a){
        if(a<l){
            return a+1;
        }
        else{
            return -(a-l+1);
        }
    };
    DINIC di;
    di.init(n+2);
    vector<pair<int,int> > e(m+1);
    vector<vector<pair<int,int> > > g(n);
    vector<int> vis(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        e[i+1]={a-1,b-1+l};
        di.add(a,b+l,1,i+1);
    }
    for(int i=0;i<l;i++){
        di.add(0,i+1,1,-1);
    }
    for(int i=0;i<r;i++){
        di.add(i+l+1,n+1,1,-1);
    }
    di.flow();
    auto p=di.get(l);
    auto sm=p.fs,df=p.sc;
    set<int> dg;
    long long sum=0;
    for(auto h:sm){
        sum+=h;
        vis[e[h].fs]=1;
        vis[e[h].sc]=1;
    }
    for(auto h:sm){
        g[e[h].fs].push_back({e[h].sc,h});
        g[e[h].sc].push_back({e[h].fs,h});
    }
    set<int> dl;
    for(auto h:df){
        if((vis[e[h].fs] xor vis[e[h].sc])==1){
            g[e[h].fs].push_back({e[h].sc,h});
            g[e[h].sc].push_back({e[h].fs,h});
        }
        else{
            if(vis[e[h].fs]){
                g[e[h].fs].push_back({e[h].sc,h});
                g[e[h].sc].push_back({e[h].fs,h});
                dg.insert(h);
            }
            dl.insert(h);
        }
    }
    for(auto h:dl){
        df.erase(h);
    }
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){   
            int del=-1;
            cout << 1 << endl;
            if(!df.empty()){
                for(auto u:df){
                    auto a=e[u].fs,b=e[u].sc;
                    if(vis[a]){
                        del=a;
                    }
                    else{
                        del=b;
                    }
                    cout << idx(del) << endl;
                    break; 
                }
            }
            else if(!dg.empty()){
                for(auto u:dg){
                    auto a=e[u].fs,b=e[u].sc;
                    if(vis[a]){
                        del=a;
                    }
                    else{
                        del=b;
                    }
                    cout << idx(del) << endl;
                    break; 
                }
            }
            else{
                for(auto u:sm){
                    auto a=e[u].fs,b=e[u].sc;
                    if(vis[a]){
                        del=a;
                    }
                    else{
                        del=b;
                    }
                    cout << idx(del) << endl;
                    break; 
                }
            }
            vis[del]=0;
            for(auto h:g[del]){
                if(sm.find(h.sc)!=sm.end()){
                    sm.erase(h.sc);
                    sum-=h.sc;
                    vis[h.fs]=0;
                    for(auto p:g[h.fs]){
                        if(vis[p.fs]){
                            dg.erase(p.sc);
                            df.insert(p.sc);
                        }
                    }
                }
                else if(dg.find(h.sc)!=dg.end()){
                    dg.erase(h.sc);
                }
                else if(df.find(h.sc)!=df.end()){
                    df.erase(h.sc);
                }
            }
            cout << sum << endl;
        }
        else{
            cout << sm.size() << endl;
            for(auto h:sm){
                cout << h << " ";
            }
            cout << endl;
        }
    }
    return 0;
}