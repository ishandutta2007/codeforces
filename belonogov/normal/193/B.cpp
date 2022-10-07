#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef double db;

const int maxn = 40;
const ll inf = 1e15;


ll ans = -inf;

int a[maxn];
int a1[maxn];
int b[maxn];
int k[maxn];
int p[maxn];
int p1[maxn];
int n, u, r;

void getans(){
    int i;
    ll ans1 = 0;
    forn(i, n)
        ans1 = ans1 + a[i] * k[i];

    ans = max(ans, ans1);
}
void xor(){
    int i;
    forn(i, n)
        a[i] = a[i] ^ b[i];
}
void f(){
    int i;
    forn(i, n)
        a1[i] = a[p[i]] + r;
    forn(i, n)
        a[i] = a1[i];
}

void f1(){
    int i;
    forn(i, n)
        a1[i] = a[p1[i]] - r;
    forn(i, n)
        a[i] = a1[i];
}


void rec(int m, int z){
    if ((u - m) % 2 == 0)
        getans();
    if (m >= u)
        return;

    if (z == 0){
        xor();
        rec(m + 1, 1);
        xor();
    }
    f();
    rec(m + 1, 0);
    f1();
}


int main(){
    int i;
    cin >> n >> u >> r;
    forn(i, n)
        cin >> a[i];
    forn(i, n)
        cin >> b[i];

    forn(i, n)
        cin >> k[i];
    forn(i, n){
        cin >> p[i];
        p[i]--;
        p1[p[i]] = i;
    }
    rec(0, 0);
    cout << ans;

    return 0;

}