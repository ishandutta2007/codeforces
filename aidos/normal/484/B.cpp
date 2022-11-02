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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 2e6 + 10;

const int maxk = (int) 1e6;

using namespace std;


int a[maxn+10];
int two[maxn+10];
int t[25][maxn+10];
int n;
void calc(){
    two[1] = 0;
    for(int i = 2; i < maxn; i++) two[i] = two[i / 2] + 1;
    for(int i = 0; i < maxn; i++) t[0][i] = a[i];
    for(int lvl = 1; (1 << lvl) <= maxn; lvl++) {
        for(int i = 0; i + (1 << lvl) <= maxn; i++) {
            t[lvl][i] = max(t[lvl - 1][i], t[lvl - 1][i + (1 << (lvl-1))]);
        }
    }
}
int get(int l, int r) {
    
    int sz = r - l + 1;
    int lvl = two[sz];
    return max(t[lvl][l], t[lvl][r - (1 << lvl) + 1]);
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        a[x] = x;
    }
    calc();
    int maxi = 0;
    for(int i = 2; i <= maxk; i++){
        if(a[i]==0) continue;
        for(int j = i; j <= maxk; j+=i){
            maxi = max(maxi, get(j, j+i-1) % i);
        }
    }
    cout << maxi << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}