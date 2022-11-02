#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

int n;
int a[200200];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }
    int mn = inf + 10;
    for(int i = 0; i < n; i++){
    	mn = min(a[i],mn);
    }
	int pos = 0, ne =-1;
	while(a[pos] != mn) pos++;
	int ans= 0;
	while(ne < pos){
		ne = pos;
		pos = (pos + 1) % n;
		while(a[pos] != mn) pos = (pos + 1) % n;
		if(ne < pos)
			ans = max(ans, pos - ne - 1);
		else 	ans = max(ans, n - ne - 1 + pos);
	}                                                 
	cout <<n *1ll * mn + ans <<endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}