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
#define prev prevvv

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;


int prev[22];
int n;
int a[100100];
vector < int > v;

bool used[2000200];
int cnt = 0;
void add(int &val){
    if(!used[val]){
        cnt++;
        used[val] = 1;
    }
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        add(a[i]);
        int p = i-1;
        int x = a[i];
        while(p > 0){
            int mx = 0;
            x |= a[p];
            for(int j = 0; j < 21; j++){
                if( prev[j] >= p || (x & ( 1<< j))) continue;
                mx = max(prev[j], mx);
            }
            add(x);
            p = mx;
        }
        for(int j = 0; j < 21; j++){
            if( a[i] & ( 1 << j)) prev[j] = i;
        }
    }
    cout << cnt << endl;
    
    
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}