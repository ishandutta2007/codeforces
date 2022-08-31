#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7 , __ = 1e7 + 7; int id[_];
struct Edge{int end , upEd , f;}Ed[__]; int head[_] , S , T , cntEd;
void init(){memset(head , 0 , sizeof(int) * (T + 1)); cntEd = 1;}
void addEd(int p , int q , int f){Ed[++cntEd] = (Edge){q , head[p] , f}; head[p] = cntEd;}
void addE(int p , int q){addEd(p , q , 1); addEd(q , p , 0);}

int dep[_] , cur[_]; queue < int > q;
bool bfs(){
	while(!q.empty()) q.pop();
	q.push(S); memset(dep , 0 , sizeof(int) * (T + 1)); dep[S] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(Ed[i].f && !dep[Ed[i].end]){
				dep[Ed[i].end] = dep[t] + 1; q.push(Ed[i].end);
				if(Ed[i].end == T){memcpy(cur , head , sizeof(int) * (T + 1)); return 1;}
			}
	}
	return 0;
}

int dfs(int x , int f){
	if(x == T) return f;
	int sum = 0;
	for(int &i = cur[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].f && dep[Ed[i].end] == dep[x] + 1){
			int t = dfs(Ed[i].end , min(Ed[i].f , f - sum)); sum += t;
			Ed[i].f -= t; Ed[i ^ 1].f += t; if(f == sum) break;
		}
	return sum;
}

int main(){
	int Case , N;
	for(cin >> Case ; Case ; --Case){
		cin >> N; T = 4 * N + 1; init(); vector < int > pot; for(int i = 1 ; i <= N ; ++i){int x; cin >> x; id[x] = i; pot.push_back(x);}
		for(int i = 0 ; i < pot.size() ; ++i){addE(S , i + 1); addE(S , 2 * N + i + 1); addE(i + 1 , 3 * N + i + 1); addE(N + i + 1 , T); addE(3 * N + i + 1 , T);}
		if(pot.size() <= 1000)
			for(int i = 0 ; i < pot.size() ; ++i)
				for(int j = 0 ; j < pot.size() ; ++j){if(i != j && pot[i] % pot[j] == 0){addE(i + 1 , N + j + 1); addE(i + 1 , 3 * N + j + 1); addE(2 * N + i + 1 , 3 * N + j + 1);}}
		else
			for(int i = 1 ; i <= 5e4 ; ++i)
				if(id[i]) for(int j = 2 * i ; j <= 5e4 ; j += i) if(id[j]){addE(id[j] , N + id[i]); addE(id[j] , 3 * N + id[i]); addE(2 * N + id[j] , 3 * N + id[i]);}
		int sum = 2 * N; while(bfs()) sum -= dfs(S , 1e9);
		cout << N - sum << '\n'; for(auto t : pot) id[t] = 0;
	}
	return 0;
}