#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

const int maxn = 2e5;

ll a[maxn];
ll b[maxn];

ll solve(int k, int n){
    ll ans = 0;
    ll step = k;
    ll i = n - 2;
    for(;i >= 0;){
        ans += b[i];
    //    cerr << "ans: " << ans << endl;
        i = i - step;
        step *= k;
    }   
    
    return ans;
}

int main(){
    int n, x, q;
    ll ans, ans1;
    cin >> n;
    forn(i, n)
        cin >> a[i];
    sort(a, a + n);
    b[0] = a[0];
    forab(i, 1, n)
        b[i] = b[i - 1] + a[i];
  /*  cerr << "b: \n";
    forn(i, n)
        cerr << b[i] << " ";
    cerr << "\n\n";
    */
    ans1 = 0;
    forn(i, n - 1)
        ans1 = ans1 + b[i];
    cin >> q;
    forn(i, q){
        cin >> x;
        if (x == 1){
            cout << ans1 << " ";
            continue;
        }
        x = min(x, n - 1);
        ans = solve(x, n);
        cout << ans << " ";
    }
    
    
        

    return 0;
}