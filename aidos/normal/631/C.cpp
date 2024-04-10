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


int n, m;
int a[200200];
int t[200200];
int r[200200];
vector < int > v, ans;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++){
    	scanf("%d %d", &r[i], &t[i]);
    }
    for(int i = 0; i < m; ++i){
    	while(v.size() > 0&& t[v.back()] <= t[i]) v.pop_back();
    	v.pb(i);
    }
    
    while(n > t[v[0]]) {
    	ans.pb(a[n-1]);
    	n--;
    }
    sort(a, a + n);
    int l = 0, rr = n - 1;
    for(int i = 0; i + 1 < v.size(); i++){
    	int id = v[i];
    	int nid = v[i+1];
    	if(r[id] == 1){
    		int len = t[id];
    		int nlen = t[nid];
    		for(int j = len; j > nlen; j--){
    			ans.pb(a[l + j - 1]);
    		}
    		rr -= len - nlen;
    	}else {
    		int len = t[id];
    		int nlen = t[nid];
    		for(int j = nlen+1; j <= len; j++){
    			ans.pb(a[l + j - nlen - 1]);
    		}
    		l += len - nlen;
    	}
    }
    if(r[v.back()] == 1){
    	while(rr >= l) ans.pb(a[rr--]);
    }
    else {
    	while(l <= rr) ans.pb(a[l++]);
    }
    reverse(all(ans));
    for(int i = 0; i < ans.size(); i++){
    	if(i) printf(" ");
    	printf("%d", ans[i]);
    }
    printf("\n");


    

    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}