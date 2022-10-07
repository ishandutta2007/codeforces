#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define forba(i, b, a) for(int i = b; i > a; i--)

typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10;
const int maxnn = 600;

int a[maxn];
int b[maxn];
int c[maxn];
int pref[maxnn][maxn];


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, l, r, uk, ans, sum;
    cin  >> n >> m;
    forn(i, n){
        cin >> a[i];
        if (a[i] <= n)
            b[a[i]]++;
    }
    uk = 0;
    forab(i, 1, n + 1)
        if (b[i] >= i)
            c[uk++] = i;
    forn(i, uk)
        forn(j, n){
            if (j) pref[i][j] = pref[i][j - 1];
            if (a[j] == c[i])
                pref[i][j]++;   
        }
    forn(i, m){
        scanf("%d%d", &l, &r); l--; r--;
        ans = 0;
        forn(j, uk){
            sum = pref[j][r];
            if (l > 0)
                sum -= pref[j][l - 1];
            if (sum == c[j])
                ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}