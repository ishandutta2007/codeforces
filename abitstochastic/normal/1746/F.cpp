#include<bits/stdc++.h>
using namespace std;

mt19937_64 rnd(time(0));
const int _ = 3e5 + 7 , S = 40; int Q , N , val[_]; unsigned int bit[S];
struct BIT{
#define lowbit(x) ((x) & -(x))
	int arr[_];
	void add(int x , int v){while(x <= N){arr[x] += v; x += lowbit(x);}}
	int qry(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}
}pot[S]; map < int , int > to;

void add(int pos , int v){for(int i = 0 ; i < S ; ++i) if(__builtin_popcount(bit[i] & v) & 1) pot[i].add(pos , 1);}
void del(int pos , int v){for(int i = 0 ; i < S ; ++i) if(__builtin_popcount(bit[i] & v) & 1) pot[i].add(pos , -1);}
void trans(int &x){
	if(to.find(x) == to.end()) to[x] = rnd() % 1000000000 + 1;
	x = to[x];
}

signed main(){
	for(int i = 0 ; i < S ; ++i) bit[i] = rnd();
	ios::sync_with_stdio(0); cin >> N >> Q; for(int i = 1 ; i <= N ; ++i){cin >> val[i]; trans(val[i]); add(i , val[i]);}
	while(Q--){
		int op; cin >> op;
		if(op == 1){int i , x; cin >> i >> x; del(i , val[i]); trans(val[i] = x); add(i , val[i]);}
		else{
			int l , r , k; cin >> l >> r >> k; bool flg = (r - l + 1) % k == 0;
			for(int i = 0 ; i < S && flg ; ++i) flg &= (pot[i].qry(r) - pot[i].qry(l - 1)) % k == 0;
			cout << (flg ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}