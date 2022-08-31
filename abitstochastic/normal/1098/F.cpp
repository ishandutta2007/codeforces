//Modified from UOJ700
#include<bits/stdc++.h>
using namespace std;

#define ui long long
const int _ = 2e5 + 7 , __ = 4e5 + 7 , T = 500; int N , M; ui w[_] , dep[_] , ans[_]; char str[_];
struct qry{int l , r , id;}; vector < qry > pot[2003]; ui nxt[_] , sum[_] , prew[_];

void brute(ui l , int r , int id){
	nxt[l - 1] = l - 2; dep[l - 1] = 0; ui S = 0;
	for(int i = l ; i <= r ; ++i){
		ui pos = nxt[i - 1]; while(pos != l - 2 && str[pos + 1] != str[i]) pos = nxt[pos];
		nxt[i] = pos + 1; dep[i] = dep[nxt[i]] + 1; S += w[i] * dep[i]; sum[i] = S;
	}
	ans[id] = sum[r];
}

//SAM
int trs[__][26] , fa[__] , len[__] , fin[__] , endp[__] , cnode = 1 , lst = 1;
void append(int l , int c){
	int t = ++cnode , p = lst; lst = t; fin[len[t] = endp[t] = l] = t; while(!trs[p][c]){trs[p][c] = t; p = fa[p];}
	if(!p){fa[t] = 1; return;} int q = trs[p][c]; if(len[q] == len[p] + 1){fa[t] = q; return;}
	int k = ++cnode; len[k] = len[p] + 1; fa[k] = fa[q]; memcpy(trs[k] , trs[q] , sizeof(trs[q])); fa[q] = fa[t] = k;
	while(trs[p][c] == q){trs[p][c] = k; p = fa[p];}
}

int dfn[__] , sz[__] , top[__] , cnttop; vector < int > ch[__]; ui val[__];
void dfs(int x){
	top[dfn[x] = ++cnttop] = x; for(auto t : ch[x]) dfs(t);
	sz[x] = cnttop - dfn[x] + 1;
}
void sam_init(){for(int i = 2 ; i <= cnode ; ++i){ch[fa[i]].push_back(i);} dfs(1);}

int lcp[_];
void funcz(int fir){
	int mx = fir + 1 , pre = fir;
	for(int i = fir + 1 ; i <= N ; ++i){
		lcp[i] = max(0 , min(mx - i , lcp[fir + i - pre])); while(i + lcp[i] <= N && str[i + lcp[i]] == str[fir + lcp[i]]) ++lcp[i];
		if(i + lcp[i] >= mx){mx = i + lcp[i]; pre = i;}
	}
}

ui sum1[503] , sum2[503] , sum3[503] , cnt[503]; vector < int > qpot[_];
struct dat{int pos , len , curpoint , id;}; vector < dat > qrpot1[_] , qrpot2[_];
ui sum4[__] , sum4_block[1003];
void sum4add(int x , int v){
	for(int i = x / T ; i <= cnode / T + 1 ; ++i) sum4_block[i] += v;
	for(int i = x ; i / T == x / T ; ++i) sum4[i] += v;
}
ui sum4qry(int x){return sum4[x] + (x < T ? 0 : sum4_block[x / T - 1]);}

int main(){
	scanf("%s %d" , str + 1 , &M); N = strlen(str + 1); for(int i = 1 ; i <= N ; ++i){w[i] = 1; append(i , str[i] - 'a'); prew[i] = prew[i - 1] + w[i];} sam_init();
	for(int i = 1 ; i <= M ; ++i){int l , r; scanf("%d %d" , &l , &r); if(r - l < 2 * T) brute(l , r , i); else{int id = l / T + 1; pot[id].push_back((qry){l , r , i});}}
	for(int i = 1 ; i <= N / T ; ++i)
		if(pot[i].size()){
			brute(i * T , N , 0); sort(pot[i].begin() , pot[i].end() , [&](qry p , qry q){return p.r < q.r;});
			for(auto t : pot[i]){
				ans[t.id] = sum[t.r] + prew[i * T - 1] - prew[t.l - 1];
				qrpot1[t.l].push_back((dat){t.l , i * T - t.l , 1 , t.id});
				qrpot2[t.r].push_back((dat){t.l , i * T - t.l , 1 , t.id});
			}
			funcz(i * T); int posq = 0; memset(sum1 , 0 , sizeof(sum1)); memset(sum2 , 0 , sizeof(sum2)); memset(sum3 , 0 , sizeof(sum3));
			memset(val , 0 , sizeof(val));
			for(int x = fin[i * T - 1] ; x ; x = fa[x]) val[x] = len[x] - len[fa[x]];
			for(int j = 2 ; j <= cnttop ; ++j) val[top[j]] += val[fa[top[j]]];
			for(int j = i * T + 1 ; j <= N ; ++j){
				int lim1 = val[fin[j - 1]] , lim2 = j + lcp[j] - 1;
				if(lim1 < T){sum3[lim1] += prew[j - 1]; ++sum1[lim1]; qpot[lim2 + 1].push_back(lim1);}
				for(auto t : qpot[j]){--sum1[t]; sum2[t] += prew[j - 1];} qpot[j].clear();
				while(posq < pot[i].size() && pot[i][posq].r == j){
					qry now = pot[i][posq++]; ui cnt = 0;
					for(int j = 0 ; j < i * T - now.l ; ++j){cnt += sum1[j]; ans[now.id] += sum3[j] - sum2[j];}
					ans[now.id] -= cnt * prew[j];
				}
			}
		}
	vector < dat > preqry , tmp;
	for(int i = 1 ; i <= N ; ++i){
		sum4add(dfn[fin[i]] , w[i]); 
		for(auto x : preqry){
			if(!x.len--) continue;
			int u = x.curpoint = trs[x.curpoint][str[x.pos] - 'a']; ++x.pos;
			ans[x.id] -= sum4qry(dfn[u] + sz[u] - 1) - sum4qry(dfn[u] - 1); tmp.push_back(x);
		}
		for(auto x : qrpot1[i]){
			if(!x.len--) continue;
			int u = x.curpoint = trs[x.curpoint][str[x.pos] - 'a']; ++x.pos;
			ans[x.id] -= sum4qry(dfn[u] + sz[u] - 1) - sum4qry(dfn[u] - 1); tmp.push_back(x);
		}
		preqry = tmp; tmp.clear();
		for(auto x : qrpot2[i]){int u = 1; for(int i = x.pos ; i < x.pos + x.len ; ++i){u = trs[u][str[i] - 'a']; ans[x.id] += sum4qry(dfn[u] + sz[u] - 1) - sum4qry(dfn[u] - 1);}}
	}
	for(int i = 1 ; i <= M ; ++i) printf("%lld\n" , ans[i]);
	return 0;
}