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
int b[500500];
int calc(int l, int r){
    if( r - l < 2) return 0;
    if( b[r] != b[l]){
        int mid = (l + r) >> 1;
        for(int i = l + 1; i <= mid; i++)
            b[i] = b[l];
        for(int i = mid + 1; i < r; i++)
            b[i] = b[r];
        return mid - l;
    }
    else {
        for(int i = l + 1; i <= r; i++){
            b[i] = b[l];
        }
        return (r - l ) /2;
    }
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    int ind = 0;
    int ans = 0;
    for(int j = 1; j < n; j++){
        if( b[j] == b[j-1]){
            int ans1 = calc(ind, j - 1);
            ind = j;
            if(ans1 == -1){
                cout << -1 << endl;
                return 0;
            }
            ans = max(ans1, ans);
        }
    }
    if(ind != n-1){
        ans = max(ans, calc(ind, n-1));
    }

    printf("%d\n" , max(ans, ans));
    for(int i = 0; i < n; i++){
        printf("%d " ,b[i]);
    }
    printf("\n");
    

    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}