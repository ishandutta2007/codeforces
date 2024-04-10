#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

const int maxn = 2e5;

typedef long long ll;
typedef double db;
struct asd{
    ll x, i;
};

asd a[maxn];
ll c[maxn];
bool use[maxn];

bool less(asd a, asd b){
    return a.x > b.x;
}

int main(){
     int n, k, i;
    ll b, sum;
    cin >> n >> k;
    cin >> b;
    forn(i, n){
        scanf("%d", &a[i].x);
        a[i].i = i;
        c[i] = a[i].x;
    }
    if (n == k)
        k--;
    n--;
    sort(a, a + n, less);
    sum = 0;
    forn(i, k){
        sum += a[i].x;
        use[a[i].i] = true;
    }
    if (sum <= b){
        cout << n + 1;
        return 0;
    }
    forn(i, n){
        if (use[i]){
            cout << i + 1;
            return 0;
        }
        if (sum - a[k - 1].x + c[i] > b){
            cout << i + 1;
            return 0;
        }
    }
    cout << n + 1;

    return 0;

}