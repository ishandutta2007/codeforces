#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (int)1e9;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n, m;
string s[111];

bool check(int x, int y, char c){
    int cnt = 0;
    for(int i = 0;  i< m; i++){
        if(s[x][i] == c) cnt++;
    }
    if(cnt > 1) return 0;
    cnt = 0;
    for(int i = 0 ; i< n; i++){
        if(s[i][y] == c) cnt++;
    }
    if(cnt > 1) return 0;
    return 1;
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    string ans = "";
    for(int i = 0; i < n; i++){
        for(int j =0; j < m; j++){
            if(check(i, j, s[i][j])){
                ans += s[i][j];
            }
        }
    }
    cout << ans << endl;
}

int main () {
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}