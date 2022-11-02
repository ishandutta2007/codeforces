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

char c[20020];
string x[100100];
int m;
int n;
int nxt[10010];
int dp[10010];
int sz = 1;
int h[1000100][27];
int id[1000100];

void add(string &x, int ii){
	int st = 0;
	int pos = (int) x.size() - 1;
	while(pos >= 0){
		int c = x[pos];
		if(c >= 'A' && c <= 'Z') c -= 'A';
		else c -= 'a';
		if(h[st][c] == -1){
			h[st][c] = sz;
			sz++;
		}
		st = h[st][c];
		pos--;
	}
	id[st]=ii;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    memset(h, -1, sizeof h);
    memset(id, -1, sizeof id);
    scanf("%d", &m);
    scanf("%s", c);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
    	cin >> x[i];
    	add(x[i], i);
    }

    dp[m] = 1;
    for(int i = m-1; i >= 0; i--){
    	int j = i, st = 0;
    	while( j<m){
    		if(h[st][c[j] - 'a'] == -1) break;
    		st = h[st][c[j] - 'a'];
    		if(id[st] != -1 && dp[j + 1]){
    			dp[i] = 1;
    			nxt[i] = id[st];
    			break;
    		}
    		j++;
    	}
    }
    for(int i = 0; i < m; ){
    	cout << x[nxt[i]] << " ";
    	i += x[nxt[i]].size();
    }
    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}