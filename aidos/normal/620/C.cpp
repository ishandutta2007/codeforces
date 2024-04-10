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


set < int > S;
vector < pii > v;
int n, a[500500];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ){
    	int j = i;
    	S.clear();
    	while(i < n && S.count(a[i])==0){
    		S.insert(a[i]);
    		i++;
    	}
    	if(i == n){
    		if(v.size()){
    			v[v.size()-1].s=n;
    			break;
    		}
    		else {
    			cout <<-1<<endl;
    			return 0;
    		}
		}
		v.pb(mp(j + 1, i + 1));
		i++;
    }
    cout << v.size() << endl;
    for(pii x: v){
    	printf("%d %d\n", x.f, x.s);
    }
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}