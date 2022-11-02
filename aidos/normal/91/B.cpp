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

int b[100100];
int a[100100];
int c[100100];
int ans[100100];
int n;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    int k = unique(b, b + n) - b;
    for(int i = 0; i <= k; i++)
        c[i] = -100;
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(b, b + k, a[i]) - b;
    }
    for(int  i = n-1; i >=0 ; i--){
        ans[i] = c[a[i]];
        int j = a[i] + 1;
        while( j < k && c[j] == -100){
            c[j] = i;
            j++;
        }
    }
    for(int i = 0; i < n; i++){
        if(i) printf(" ");
        printf("%d", max(ans[i]-i, 0) - 1);
    }
    printf("\n");

    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}