// nlog^2 + mlog. commmme on
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

	
const int maxn = 2e5 + 10;

int n, a[maxn], b[maxn], Ind[maxn];
ordered_set<int> fen[maxn];

int get(int idx, int mxm, int mnm){
    int ret = 0;
    for (; idx; idx -= idx & -idx)
        ret += fen[idx].order_of_key(mxm + 1) - fen[idx].order_of_key(mnm);
    return ret;
}

void del(int idx, int val){
    for (; idx <= n; idx += idx & -idx)
        fen[idx].erase(val);
}

void add(int idx, int val){
    for (; idx <= n; idx += idx & -idx)
        fen[idx].insert(val);
}

int main(){
	int m;
    scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
		Ind[a[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		int x;
        scanf("%d", &x);
		b[i] = Ind[x];
        add(i, b[i]);
	}
	while (m --){
		int type;
        scanf("%d", &type);
		if (type == 1){
			int La, Ra, Lb, Rb;
            scanf("%d%d%d%d", &La, &Ra, &Lb, &Rb);
			printf("%d\n", get(Rb, Ra, La) - get(Lb - 1, Ra, La));
		}
		else{
			int x, y;
		    scanf("%d%d", &x, &y);
			if (x > y)
			    swap(x, y);
		    del(x, b[x]);
		    del(y, b[y]);
		    add(x, b[y]);
		    add(y, b[x]);
			swap(b[x], b[y]);
		}
	}
}