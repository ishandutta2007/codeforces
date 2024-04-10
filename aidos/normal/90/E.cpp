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
#include<bitset>
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

bitset<5050>d[5050];
bitset<5050>a[5050];
bitset<5050>d2[5050];
bitset<5050>a2[5050];

int n, m;
char x[5050][5050];
int cc = 0;

void reset(){
    for(int i = 0; i < n; i++){
        for(int j = 0;j <m; j++){
            if(x[i][j] == '.'){
                a[i][j] = 0;
                d[j][i] = 0;
                a2[i][m-j] = 0;
                d2[j][n-i] = 0;
            }
            else{
                a[i][j] = 1;
                d[j][i] = 1;
                a2[i][m-j] = 1;
                d2[j][n-i] = 1;
            }
        }
        a[i][5002] = 1;
        a2[i][5002] = 1;
    }
    for(int i = 0; i < m; i++){
        d[i][5002] = 1;
        d2[i][5002] = 1;
    }
}

int go(int i, int j){
    a[i][j] = 0;
    d[j][i] = 0;
    a2[i][m-j] = 0;
    d2[j][n-i] = 0;
    int cur = 0;
    if(x[i][j] == 'U'){
        int pos = d2[j]._Find_next(n-i);
        if(pos!=5002){
            cur = go(n - pos, j);
        }
    }else if(x[i][j] == 'D'){
        int pos = d[j]._Find_next(i);
        if(pos!=5002){
            cur = go(pos, j);
        }
    } else if(x[i][j] == 'L'){
        int pos = a2[i]._Find_next(m-j);
        if(pos!=5002){
            cur = go(i, m - pos);
        }
    }else if(x[i][j] == 'R'){
        int pos = a[i]._Find_next(j);
        if(pos!=5002){
            cur = go(i, pos);
        }
    }
    return cur + 1;  
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    int ans = -inf;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(x[i][j] == '.') continue;
            reset();
            int cur = go(i, j);
            if(cur > ans){
                ans = cur;
                cnt = 1;
            }
            else if(ans==cur){
                cnt++;
            }
        }
    }
    cout << ans << " "<<cnt<<endl;
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