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

pii x[111];
int n;

bool isOk(int a, int b){
	for(int i = 0; i<3; i++){
		if(x[i].f == a) continue;
		if(x[i].s == b) continue;
		return 0;
	}
	return 1;
}

bool between(int a, int b){
	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 3; j++){
			if(x[i].f == x[j].f && a == x[i].f){
				if(x[i].s < b && x[j].s > b) return 1;
			}
			if(x[i].s == x[j].s && b == x[j].s){
				if(x[i].f < a && x[j].f > a) return 1;
				if(x[i].f > a && x[j].f < a) return 1;
			}
		}
	}
	return 0;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    for(int i = 0; i < 3; i++){
    	cin>>x[i].f >> x[i].s;
    }
    sort(x, x + 3);
    if(x[0].f == x[2].f || (x[0].s == x[1].s && x[1].s ==x[2].s)){
    	cout << 1 << endl;
    	return 0;
    }
    for(int i = 0; i < 3; i++){
    	for(int j = 0; j < 3; j++){
    		if(isOk(x[i].f, x[j].s) && !between(x[i].f, x[j].s)){
    			cout << 2 << endl;	
    			return 0;
    		}
    	}
    }
    cout << 3 << endl;

    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}