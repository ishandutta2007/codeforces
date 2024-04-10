#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;
struct num{
    int x, i;
};

num a[400000];
int b[400000];
bool less1(num a, num b){
    return (a.x < b.x || (a.x == b.x && a.i < b.i));
}

int main(){
   int i, n, k, kol, x;
    ll ans;
    cin >> n >> k;
    if (k == 1){
        ans = n;
        cout << ans * (ans + 1) / 2;
        return 0;
    }
    forn(i, n){
        scanf("%d", &a[i].x);
        a[i].i = i;
    }
    memset(b, -1, sizeof(b));
    sort(a, a + n, less1);
    kol = 1;

    forab(i, 1, n){
        if (a[i - 1].x == a[i].x)
            kol++;
        else
            kol = 1;
        if (kol >= k){
            b[a[i].i] = max(b[a[i].i], a[i - k + 1].i + 1);
        }

    }
    x = -1;
    forn(i, n){
        x = max(b[i], x);
        b[i] = x;
    }
    ans = 0;
    forn(i, n){
        if (b[i] != -1) 
            ans = ans + b[i];
    }
    cout << ans;
    return 0;

}