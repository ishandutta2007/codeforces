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

int a[800400], n;
ll k;
int b[800400];
int mxn = 400000;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n >> k;
    for(int i = 0; i <= n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i <= n; i++){
    	b[i] = a[i];
    }
    vector < int > v2, v1;
    for(int i = 0; i <= n; i++){
    	b[i+1] += b[i]/2;
    	int x = abs(b[i]);
    	if(x % 2 == 0){
    		b[i] = 0;
    	}
    	else if(b[i] < 0){
    		b[i] = -1;
    	}else b[i] = 1;
    }
    int m = n;
    n++;
    while(b[n] != 0){
    	
    	b[n+1] += b[n]/2;
    	int x = abs(b[n]);
    	if(x % 2 == 0){
    		b[n] = 0;
    	}
    	else if(b[n] < 0){
    		b[n] = -1;
    	}else b[n] = 1;
    	n++;
    }
    for(int i = 0; i < n; i++){
    	if(b[i] == 1) v1.pb(i);
    	else if(b[i] == -1) v2.pb(i);
    }
    if(v1.size() == 0 || (v2.size() > 0 && v2.back() > v1.back())){
    	for(int i = 0; i <=m ;i++)
    		a[i] *= -1;
		for(int i = 0; i < n; i++)
			b[i] *= -1;
		v1.clear();
		v2.clear();
		for(int i = 0; i < n; i++){
    			if(b[i] == 1) v1.pb(i);
		    	else if(b[i] == -1) v2.pb(i);
    	}
    }	
    int x1 = 0, x2 = 0;
    vector < int > v;
    while(x1 < v1.size()&&x2<v2.size()){
    	if(v1[x1] < v2[x2]){
    		while(x1 < v1.size() && v1[x1] < v2[x2]) {
    			v.pb(v1[x1]);
    			x1++;
    		}
    	}
    	else {
    		int j = x2;
    		while(x2 < v2.size() && v1[x1] > v2[x2]) x2++;
    		int st = j+1;
    		v.pb(v2[j]);
    		for(int i = v2[j]+1; i < v1[x1]; i++){
    			if(st < v2.size() && v2[st] == i) {
    				st++;
    				continue;
    			}
    			v.pb(i);
    		}
    		x1++;
    	}
    }
    while(x1<v1.size()){
    	v.pb(v1[x1]);
    	x1++;
    }

    int ind = v[0];
    int la = v.back();


    ll ans = 0;
    for(int i = 0; i <= min(ind, m); i++){
    	if(la - i > 40) continue;
    	ll cur = 0;

    	for(int j = 0; j < v.size(); j++){
    		cur += (1ll<<(v[j] - i));
    	}
    	cur -= a[i];
    	if(cur < 0) cur *= -1;
    	if(cur <= k) {
    		if(i == m && cur == 0) continue;
    		ans++;
    	}
    }
    cout<<ans <<endl;


    



    




    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}