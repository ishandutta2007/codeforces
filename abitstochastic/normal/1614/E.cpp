#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7 , __ = _ * 240; int N;
#define mid ((l + r) >> 1)
int mrk[__] , ch[__][2] , mn[__] , mx[__] , cnt;
int create(int L , int R){int t = ++cnt; mn[t] = L; mx[t] = R; return t;}
void mark(int &x , int v){mrk[x] += v; mn[x] += v; mx[x] += v;}
void pushdown(int x , int l , int r){
	if(l == r) return;
	if(!ch[x][0]) ch[x][0] = create(l , mid);
	if(!ch[x][1]) ch[x][1] = create(mid + 1 , r);
	mark(ch[x][0] , mrk[x]); mark(ch[x][1] , mrk[x]); mrk[x] = 0;
}
void upd(int x){mn[x] = min(mn[ch[x][0]] , mn[ch[x][1]]); mx[x] = max(mx[ch[x][0]] , mx[ch[x][1]]);}
void mark(int x , int l , int r , int L , int R , int v){
	if(l >= L && r <= R) return mark(x , v);
	pushdown(x , l , r);
	if(mid >= L) mark(ch[x][0] , l , mid , L , R , v);
	if(mid < R) mark(ch[x][1] , mid + 1 , r , L , R , v);
	upd(x);
}
int qL(int x , int l , int r , int v){
	if(l == r) return l;
	pushdown(x , l , r); if(mn[ch[x][1]] <= v) return qL(ch[x][1] , mid + 1 , r , v);
	return qL(ch[x][0] , l , mid , v);
}
int qR(int x , int l , int r , int v){
	if(l == r) return l;
	pushdown(x , l , r); if(mx[ch[x][0]] >= v) return qR(ch[x][0] , l , mid , v);
	return qR(ch[x][1] , mid + 1 , r , v);
}
int qry(int x , int l , int r , int t){
	if(!x) return t;
	if(l == r) return mn[x];
	return (mid >= t ? qry(ch[x][0] , l , mid , t) : qry(ch[x][1] , mid + 1 , r , t)) + mrk[x];
}

int main(){
	ios::sync_with_stdio(0); cin >> N; create(0 , 1e9); int lastans = 0;
	for(int i = 1 ; i <= N ; ++i){
		int T; cin >> T;
		if(mn[1] < T) mark(1 , 0 , 1e9 , 0 , qL(1 , 0 , 1e9 , T - 1) , 1);
		if(mx[1] > T) mark(1 , 0 , 1e9 , qR(1 , 0 , 1e9 , T + 1) , 1e9 , -1);
		int K; cin >> K; while(K--){int p; cin >> p; p = (p + lastans) % (1000000000 + 1); cout << (lastans = qry(1 , 0 , 1e9 , p)) << '\n';}
	}
	return 0;
}