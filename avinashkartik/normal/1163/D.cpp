#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  4e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll dp[1005][55][55];
vector <vector<int>> autt, auts;
string a, s, t;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}

ll mem(int i, int j, int k) {
	if(i == a.size()) return 0;
	if(dp[i][j][k] != -INFi) return dp[i][j][k];
	if(a[i] != '*') {
		int nxts = auts[j][a[i] - 'a'];
		int nxtt = autt[k][a[i] - 'a'];
		dp[i][j][k] = mem(i + 1, nxts, nxtt) + (nxts == s.size()) - (nxtt == t.size());
	} else {
		for(int ii = 0; ii < 26; ii++) {
			int nxts = auts[j][ii];
			int nxtt = autt[k][ii];
			dp[i][j][k] = max(dp[i][j][k], mem(i + 1, nxts, nxtt) + (nxts == s.size()) - (nxtt == t.size()));
		}
	}
	return dp[i][j][k];
}

void solve() {
	cin >> a >> s >> t;
	compute_automaton(s, auts);
	compute_automaton(t, autt);
	for(int i = 0; i < a.size() + 2; i++) {
		for(int j = 0; j < s.size() + 2; j++) {
			for(int k = 0; k < t.size() + 2; k++) {
				dp[i][j][k] = -INFi;
			}
		}
	}
	deb1(mem(0, 0, 0))
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}