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

const ll   N     =  2e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, dp[N][N];
string s;

int mem(int i, int j) {
    if (j - i == 1) return s[i] == s[j]? 0 : 1;
    if (dp[i][j] != -2) return dp[i][j];
    
    if (mem(i + 2, j) == -1 || mem(i + 1, j - 1) == -1) dp[i][j] = max(dp[i][j], -1);
    else if (mem(i + 2, j) == 0 && s[i] > s[i + 1]) dp[i][j] = max(dp[i][j], -1);
    else if (mem(i + 1, j - 1) == 0 && s[i] > s[j]) dp[i][j] = max(dp[i][j], -1);
    else if (mem(i + 2, j) == 0 && s[i] == s[i + 1]) dp[i][j] = max(dp[i][j], 0);
    else if (mem(i + 1, j - 1)== 0 && s[i] == s[j]) dp[i][j] = max(dp[i][j], 0);
    else dp[i][j] = max(dp[i][j], 1);
    
    if (mem(i, j - 2) == -1 || mem(i + 1, j - 1) == -1) dp[i][j] = max(dp[i][j], -1);
    else if (mem(i, j - 2) == 0 && s[j] > s[j - 1]) dp[i][j] = max(dp[i][j], -1);
    else if (mem(i + 1, j - 1) == 0 && s[j] > s[i]) dp[i][j] = max(dp[i][j], -1);
    else if (mem(i, j - 2) == 0 && s[j] == s[j - 1]) dp[i][j] = max(dp[i][j], 0);
    else if (mem(i + 1, j - 1) == 0 && s[i] == s[j]) dp[i][j] = max(dp[i][j], 0);
    else dp[i][j] = max(dp[i][j], 1);
    
    return dp[i][j];
}

void solve() {
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            dp[i][j] = -2;
    int ans = mem(0, n - 1);
    if (ans == 1) deb1("Alice")
    else if (ans == 0) deb1("Draw")
    else deb1("Bob")
}

int main() {
	GODSPEED;
	int test = 1;
    cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}