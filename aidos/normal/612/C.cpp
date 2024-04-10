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

char op[] = { '[', '{', '<', '('};
char cl[] = { ']', '}', '>', ')'};

vector < int > ope;

int get(char x, char c[]){
	for(int i = 0; i < 4; i++)
		if(c[i] == x) return i;
	return -1;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string s;
    cin >> s;
    int cnt = 0;
    int n = s.size();
    for(int i = 0; i < n; i++){
    	if(get(s[i], op) >= 0) {
    		ope.pb(get(s[i], op));
    	}
    	else {
    		if(ope.size() == 0){
    			cout << "Impossible\n";
    			return 0;
    		}
    		cnt += ope.back() != get(s[i], cl);
    		ope.pop_back();
    	}
    }
    if(ope.size()) cout << "Impossible\n";
    else cout << cnt << endl;
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}