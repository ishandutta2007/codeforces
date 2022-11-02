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
string a;
int ok[10];
char c[]  = {'B', 'G', 'R'};
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    cin >> a;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 3; j++){
    		if(c[j] == a[i]) ok[j] = 1;
    	}
    }
    int cnt = 0;
    for(int i = 0; i < 3; i++)
    	cnt += ok[i];
    if(cnt == 1){
    	for(int i = 0; i < 3; i++){
    		if(ok[i]){
    			cout << c[i];
    			return 0;
    		}
    	}
    }
    if(cnt == 3){
    	for(int i = 0; i < 3; i++)
    		cout << c[i];
		cout << endl;
    	return 0;
    }
    for(int i = 0; i < 3; i++){
    	if(ok[i]){
    		int cnt = 0;
    		for(int j = 0; j < n; j++){
    			if(a[j] == c[i]) continue;
    			cnt++;
    		}
    		if(cnt > 1){
    			cout << c[i];
    		}
    	}
    	else {
    		cout << c[i];
    	}
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}