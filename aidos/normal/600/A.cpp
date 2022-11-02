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

int ok(string &x){
	if( x.size() == 0) return 0;
	for(int i = 0; i < x.size(); i++){
		if(x[i] >= '0' && x[i] <= '9') continue;
		return 0;
	}
	if(x[0] == '0'){
		return x.size() == 1;
	}
	return 1;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string s, t, a, b;
    cin >> s;

    bool oka = 0, okb = 0;

    for(int i = 0; i < s.size(); i++){
    	if(s[i] == ',' || s[i] == ';') {
    		if(ok(t)){
		    	if(oka) a += ',';
    			a += t;
    			oka = 1;
    		}
    		else {
    			if(okb) b+= ',';
    			b += t;
    			okb = 1;
    		}
    		t = "";
    	}
    	else t += s[i];
    }
    if( ok(t)){
    	if(oka) a += ',';
    	a += t;
    	oka = 1;
    }
    else {
    	if(okb) b += ',';
    	b += t;
    	okb = 1;
    }
    if(!oka) a = "-";
    else {
    	a = "\"" + a + "\"";

    }
    if(!okb) b = "-";
    else 
    	b = "\"" + b + "\"";
    cout << a << endl << b << endl;
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}