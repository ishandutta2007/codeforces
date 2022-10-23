//weak random
#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,k,d[6],a[55][55],ans=orz,res,f[55],cnt;
vector<pair<int,int> >v[105];
int get(int x){return x==f[x]?x:f[x]=get(f[x]);}
void sol(){
		vector<int> V;
		for(int i=1;i<=n;++i)V.pb(f[i]);
		int R=res,C=cnt;
		vector<int> q;
	for(int i=1;i<=100;++i){
		for(int j=0;j<v[i].size();++j){
			int x=v[i][j].first,y=v[i][j].second;
			if(x<=k||y<=k||get(x)==get(y)) continue;
			f[f[y]]=f[x];
			res+=a[x][y];
		}
		for(int j=0;j<v[i].size();++j){
			int x=v[i][j].first,y=v[i][j].second;
			if((x>k&&y>k)||get(x)==get(y)) continue;
			if(x<=k){
				if(!d[x]) continue;
				--d[x];
				q.pb(x);
				++cnt;
			}
			if(y<=k){
				if(!d[y]) continue;
				--d[y];
				q.pb(y);
				++cnt;
			}
			f[f[y]]=f[x];
			res+=a[x][y];
		}
	}
	for(int i=0;i<q.size();++i)++d[q[i]];
	q.clear();
	if(cnt==n-1)ans=min(ans,res);
	for(int _=0;_<100;++_){
		for(int i=1;i<=n;++i)f[i]=V[i-1];
		res=R;
		cnt=C;
	for(int i=1;i<=100;++i){
		random_shuffle(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();++j){
			int x=v[i][j].first,y=v[i][j].second;
			if(x<=k||y<=k||get(x)==get(y)) continue;
			f[f[y]]=f[x];
			res+=a[x][y];
			++cnt;
		}
		for(int j=0;j<v[i].size();++j){
			int x=v[i][j].first,y=v[i][j].second;
			if((x>k&&y>k)||get(x)==get(y)) continue;
			if(rand()<2000) continue;
			if(x<=k){
				if(!d[x]) continue;
				--d[x];
				q.pb(x);
			}
			if(y<=k){
				if(!d[y]) continue;
				--d[y];
				q.pb(y);
			}
			f[f[y]]=f[x];
			res+=a[x][y];
			++cnt;
		}
	}
		if(cnt==n-1)ans=min(ans,res);
		
	for(int i=0;i<q.size();++i)++d[q[i]];
	q.clear();
	}
	for(int _=0;_<100;++_){
		for(int i=1;i<=n;++i)f[i]=V[i-1];
		res=R;
		cnt=C;
	for(int i=1;i<=100;++i){
		random_shuffle(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();++j){
			int x=v[i][j].first,y=v[i][j].second;
			if(x<=k||y<=k||get(x)==get(y)) continue;
			f[f[y]]=f[x];
			res+=a[x][y];
			++cnt;
		}
		for(int j=0;j<v[i].size();++j){
			int x=v[i][j].first,y=v[i][j].second;
			if((x>k&&y>k)||get(x)==get(y)) continue;
			if(rand()<6000) continue;
			if(x<=k){
				if(!d[x]) continue;
				--d[x];
				q.pb(x);
			}
			if(y<=k){
				if(!d[y]) continue;
				--d[y];
				q.pb(y);
			}
			f[f[y]]=f[x];
			res+=a[x][y];
			++cnt;
		}
	}
		if(cnt==n-1)ans=min(ans,res);
		
	for(int i=0;i<q.size();++i)++d[q[i]];
	q.clear();
	}
	
	for(int _=0;_<100;++_){
		for(int i=1;i<=n;++i)f[i]=V[i-1];
		res=R;
		cnt=C;
	for(int i=1;i<=100;++i){
		random_shuffle(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();++j){
			int x=v[i][j].first,y=v[i][j].second;
			if(x<=k||y<=k||get(x)==get(y)) continue;
			f[f[y]]=f[x];
			res+=a[x][y];
			++cnt;
		}
		for(int j=0;j<v[i].size();++j){
			int x=v[i][j].first,y=v[i][j].second;
			if((x>k&&y>k)||get(x)==get(y)) continue;
			if(rand()<16000) continue;
			if(x<=k){
				if(!d[x]) continue;
				--d[x];
				q.pb(x);
			}
			if(y<=k){
				if(!d[y]) continue;
				--d[y];
				q.pb(y);
			}
			f[f[y]]=f[x];
			res+=a[x][y];
			++cnt;
		}
	}
		if(cnt==n-1)ans=min(ans,res);
		
	for(int i=0;i<q.size();++i)++d[q[i]];
	q.clear();
	}
	for(int i=1;i<=n;++i)f[i]=V[i-1];
		res=R;
		cnt=C;
}
void dfs(int x,int y){
	if(x>k){
		sol();
		return;
	}
	if(y>k){
		dfs(x+1,x+2);
		return;
	}
	if(d[x]&&d[y]&&get(x)!=get(y)){
		vector<int> V;
		for(int i=1;i<=n;++i)V.pb(f[i]);
		f[f[y]]=f[x];
		--d[x],--d[y];
		res+=a[x][y];
		++cnt;
		dfs(x,y+1);
		--cnt;
		res-=a[x][y];
		++d[x],++d[y];
		for(int i=1;i<=n;++i)f[i]=V[i-1];
	}
	dfs(x,y+1);
}
int main(){
	srand(time(0));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)scanf("%d",d+i);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			scanf("%d",a[i]+j);
			a[j][i]=a[i][j];
			if(i>k||j>k)v[a[i][j]].pb(mp(i,j));
		}
	}
	dfs(1,2);
	printf("%d\n",ans);
    return 0;
}