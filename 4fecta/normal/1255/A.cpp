#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int T,A,B;

int main() {
	boost();

	cin>>T;
	while(T--){
		cin>>A>>B;
		int r = abs(A-B)/5;
		if(A < B) A+=r*5;
		else A-=r*5;
		int r2 = abs(A-B)/2;
		if(A < B) A+=r2*2;
		else A-=r2*2;
		int r3 = abs(A-B);
		printf("%d\n",r+r2+r3);
	}

	return 0;
}