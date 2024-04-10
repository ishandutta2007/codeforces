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

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

char s[500500];
int n;
vector<int> ans;
int b[500500];
int check(int i, int len){
    if(i + len < n && !(s[i + len] == '?' || s[i+len] == s[i])) return 1;
    
    return 0;
}
void solve(){
    scanf("%d%s",&n, s);
    for(int i = 1; i <= n; i++)
        b[i] = 0;
    ans.clear();
    vector<int> p;
    //for(int i =0 ; i < n; i++)
    //    if(s[i] != '?') p.pb(i);
    int cost = n * 500;
    for(int i = n-1; i>=1; i--){
        int x = n - 1 - i;
        if(s[x] != '?') p.pb(x);

        for(int j = i; j <= n; j+=i){
            b[i] |= b[j];
        }
        if(p.size() == 0) continue;
        int iter = cost/i;
        for(int j = 0; j < iter && !b[i]; j++){
            b[i] |= check(p[rand() % p.size()], i);
            cost--;
        }
    }
    for(int i = 1; i <= n; i++)
        if(!b[i]) ans.pb(i);
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}