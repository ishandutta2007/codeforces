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

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;


int n;
int a[1001000];
int sum[5001000];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum[a[i]]++;
    }
    for(int i = 0; i < 5000100; i++){
        if( sum[i] > 0){
            sum[i+1] += sum[i]/2;
            sum[i] %= 2;
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < 5000100; i++){
        if(sum[i] == 1) cnt++;
    }
    cout << cnt << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}