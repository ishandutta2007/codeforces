
// Problem : D. Reachable Strings
// Contest : Codeforces - Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL : https://codeforces.com/contest/1320/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	int len;
	bool pre, suf;
	long long hsh;
	int cnt;
};
mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int N;
string s;
int Q;
long long sd;
const long long MOD = 1e9+7;
long long invsd;
long long pows[200005];
Node seg[1000005];
Node n;

long long mult(long long a, long long b){
	return (a*b)%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long sub(long long a, long long b){
	a = add(a, -b);
	if(a < 0){
		a += MOD;
	}
	return a;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret, ret);
	if(e&1){
		ret = mult(ret, b);
	}
	return ret;
}

Node pu(Node lft, Node rht){
	n.l = lft.l;
	n.r = rht.r;
	n.cnt = lft.cnt + rht.cnt;
	n.hsh = 0;
	if(lft.suf && rht.pre){
		//cout << "merge" << "\n";
		assert(lft.len <= 200000 && lft.len > 0);
		n.hsh = sub(lft.hsh, pows[lft.len-1]);
		//cout << n.hsh << "\n";
		n.hsh = add(n.hsh, mult(mult(invsd, pows[lft.len-1]), sub(rht.hsh, 1)));
		//cout << n.hsh << "\n";
		//cout << invsd << " " << pows[lft.len-1] << "\n";
		n.len = lft.len + rht.len - 2;
		assert(n.len >= 0);
		n.pre = ((lft.len >= 2) ? lft.pre : 0);
		n.suf = ((rht.len >= 2) ? rht.suf : 0);
	}
	else{
		n.hsh = add(lft.hsh, mult(pows[lft.len], rht.hsh));
		n.len = lft.len + rht.len;
		n.pre = (lft.len == 0 ? rht.pre : lft.pre);
		n.suf = (rht.len == 0 ? lft.suf : rht.suf);
	}
	return n;
}

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		seg[idx].hsh = s[l-1] == '1';
		seg[idx].cnt = seg[idx].hsh;
		seg[idx].len = 1;
		seg[idx].pre = seg[idx].suf = seg[idx].hsh;
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	seg[idx] = pu(seg[2*idx], seg[2*idx+1]);
	//cout << seg[idx].l << " " << seg[idx].r << " " << seg[idx].hsh << "\n";
}

Node query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx];
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else{
		return pu(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s >> Q;
	sd = uniform_int_distribution<long long> (MOD/2, MOD-1) (rando);
	pows[0] = 1;
	invsd = qikpow(sd, MOD-2);
	for(int i = 1; i<=N; i++){
		pows[i] = mult(pows[i-1], sd);
	}
	build(1, N, 1);
	while(Q--){
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		Node n1 = query(l1, l1+len-1, 1), n2 = query(l2, l2+len-1, 1);
		//cout << n1.hsh << " " << n1.cnt << " " << n2.hsh << " " << n2.cnt << "\n";
		if(n1.hsh == n2.hsh && n1.cnt == n2.cnt && n1.len == n2.len){
			cout << "Yes\n";
		}
		else{
			/*
			if(N - Q == 3370 && N == 10000){
				cout << n1.hsh << " " << n2.hsh << "\n";	
				cout << s.substr(l1-1, len) << " " << s.substr(l2-1, len) << "\n";
			}
			*/
			cout << "No\n";
		}
	}
}