#include<bits/stdc++.h>
using namespace std;

namespace blossom{
	vector < int > nxt[1803]; int N , match[1803] , dep[1803] , pre[1803][2] , cnt , fa[1803]; queue < int > que;
	int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

	int id[1803][1803];
	void adde(int p , int q , int i){if(p != q){nxt[p].push_back(q); nxt[q].push_back(p); id[p][q] = id[q][p] = i;}}
	
	void shrink(int x , int y){
		int p = find(x) , q = find(y); pre[p][0] = y; pre[p][1] = x; pre[q][0] = x; pre[q][1] = y;
		while(p != q){
			if(dep[p] < dep[q]) swap(p , q);
			int x = match[p] , y = find(pre[x][0]);
			pre[y][0] = x; pre[y][1] = pre[x][0]; p = y;
		}
		int rt = p; pre[rt][0] = pre[rt][1] = 0;
		x = find(x); while(x != rt){--dep[match[x]]; fa[x] = fa[match[x]] = rt; que.push(match[x]); x = find(pre[match[x]][0]);}
		y = find(y); while(y != rt){--dep[match[y]]; fa[y] = fa[match[y]] = rt; que.push(match[y]); y = find(pre[match[y]][0]);}
	}
	
	void getroute(int x , int tar , int to){
		if(x != tar){getroute(pre[match[x]][1] , match[x] , 0); getroute(pre[match[x]][0] , tar , pre[match[x]][1]);}
		match[x] = to; match[to] = x;
	}
	
	bool go(int x){
		memset(dep , 0 , sizeof(dep)); dep[x] = 1; while(!que.empty()) que.pop();
		que.push(x); for(int i = 1 ; i <= N ; ++i) fa[i] = i;
		while(!que.empty()){
			int t = que.front(); que.pop();
			for(auto p : nxt[t])
				if(!dep[p]){
					dep[p] = dep[t] + 1; pre[p][0] = t; pre[p][1] = p;
					if(!match[p]){getroute(t , x , p); return 1;} else{dep[match[p]] = dep[t] + 2; que.push(match[p]);}
				}
				else if((dep[p] ^ dep[t] ^ 1) & 1) shrink(p , t);
		}
		return 0;
	}
	
	void main(){for(int i = 1 ; i <= N ; ++i) if(!match[i]) go(i);}
}

int vis[300003] , A[300003] , N , cnode; bool vis1[300003];
vector < pair < int , int > > nxt1[603];
void adde1(int x , int y , int id){++cnode; blossom::adde(x , cnode , id); blossom::adde(y , cnode , id);}
void dfs1(int x , int preid , bool &flg){
	vis1[x] = 1;
	for(auto t : nxt1[x])
		if(!vis1[t.first]){dfs1(t.first , t.second , flg); adde1(t.first , x , t.second);}
		else if(t.second != preid && !flg){flg = 1; adde1(t.first , x , t.second);}
}
void fill(int x , int p){
	int L = x , R = x;
	while(L > 1 && A[L - 1] == 0) --L;
	if(R < N && A[R + 1] == 0) ++R;
	if((R - L) & 1){A[L] = A[L - 1]; A[R] = A[R + 1];}
	else A[L - 1] == p ? A[L] = A[L - 1] : A[R] = A[R + 1];
}

int main(){
	cin >> N; bool flg = 1; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; flg &= A[i] == 0; if(A[i] == A[i - 1]) vis[A[i]] = i;} cnode = 600;
	if(flg){for(int i = 0 ; i < N ; ++i){cout << (i / 2) + 1 << ' ';} return 0;}
	set < pair < int , int > > ed;
	for(int i = 1 ; i <= N ; ++i)
		if(!A[i]){
			int L = i; while(i < N && !A[i + 1]) ++i;
			int p = A[L - 1] , q = A[i + 1]; if(p > q) swap(p , q);
			if(!((i - L) & 1))
				if(!p) nxt1[q].push_back(make_pair(q , i));
				else{nxt1[p].push_back(make_pair(q , i)); nxt1[q].push_back(make_pair(p , i));}
			else if(p && ed.find(make_pair(p , q)) == ed.end()){blossom::adde(p , q , i); ed.insert(make_pair(p , q));}
		}
	for(int i = 1 ; i <= 600 ; ++i) if(!vis1[i]){bool flg = 0; dfs1(i , 0 , flg);}
	for(int i = 1 ; i <= 600 ; ++i) if(vis[i]) blossom::adde(++cnode , i , 0);
	blossom::N = cnode; blossom::main();
	for(int i = 1 ; i <= 600 ; ++i)
		if(blossom::match[i]){int p = blossom::match[i] , r = blossom::id[p][i]; blossom::match[i] = blossom::match[p] = 0; if(r) fill(r , i);}
	for(int i = 1 ; i <= N ; ++i) if(A[i] == A[i - 1]) vis[A[i]] = i;
	int pos = 1;
	for(int i = 1 ; i <= N ; ++i)
		if(!A[i]){
			while(vis[pos]) ++pos;
			A[i] = pos; if(!A[i + 1]) A[i + 1] = pos;
			++pos; cout << A[i] << ' ';
		}else cout << A[i] << ' ';
	return 0;
}