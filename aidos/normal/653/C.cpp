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

int a[200200];
int u[200200];

int n;

bool ok(){
	for(int i = 0; i < n - 1; i++){
		if(i % 2){
			if(a[i] <= a[i + 1]) return 0;
			continue;
		}
		if(a[i] >= a[i + 1]) return 0;
	}
	return 1;
}

int val(int pos, int x1, int x2){
	if(pos) return x1 < x2;
	return x1 > x2;
}

int val(int x){
	int cnt= 0;
	if(x + 1 < n )
		cnt += val((x + 1) % 2, a[x], a[x + 1]);
		
	if(x > 0)
		cnt += val(x % 2, a[x-1], a[x]);
	return cnt;
}

int get(int cnt, int x, int y){
	cnt -= val(x);
	cnt -= val(y);
	swap(a[x], a[y]);
	cnt += val(x);
	cnt += val(y);
	swap(a[x], a[y]);
	return cnt;
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    vector < int > g;
    int ans=0;
    for(int i = 1; i < n; i++){
    	if(i & 1){
    		if(a[i] <= a[i-1]) {
    			g.pb(i);
    		}
    	}
    	else {
    		if(a[i] >= a[i-1]) {
    			g.pb(i);  
    		}
    	}
    }

    sort(all(g));
    g.resize(unique(all(g)) - g.begin());
    int cnt = n - (int) g.size() - 1;
    if(g.size() > 4){
    	cout << 0 << endl;
    	return 0;
    }
    /*if(n < 300){
    	for(int i = 0; i < n; i++){
    		for(int j = i+1; j <n; j++){
    			swap(a[i], a[j]);
    			ans += ok();
    			swap(a[i], a[j]);
    		}
    	}
    	cout << ans << endl;
    	return 0;
    } */
    set < pii > S;

	vector< int > t;
	for(int i = 0; i < g.size(); i++){
		t.pb(g[i]);
		if(g[i])t.pb(g[i]-1);
		if(g[i] < n - 1) t.pb(g[i]+1);
	}
	sort(all(t));
	g.clear();
	for(int i = 0; i < t.size(); i++)
		if(i == 0 ||t[i] != t[i-1])g.pb(t[i]);

	for(int j = 0; j < g.size(); j++){
		for(int i = 0; i < n; i++){
			if(abs(i - g[j]) <= 1) continue;
			if(get(cnt, i, g[j]) == n-1){
				S.insert(mp(i, g[j]));
				S.insert(mp(g[j], i));
			}
		}
	}
	for(int j = 1; j < g.size(); j++){
		swap(a[g[j]], a[g[j-1]]);
		if(ok()){
			S.insert(mp(g[j], g[j-1]));
			S.insert(mp(g[j-1], g[j]));
		}
		swap(a[g[j]], a[g[j-1]]);
	}
	for(pii xx: S){
		//cout << xx.f << " "<< xx.s << endl;
	}
	ans = S.size();
	ans/=2;
	cout << ans << endl;


    

    
    

    


    
    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}