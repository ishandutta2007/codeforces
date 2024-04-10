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
const int maxn = (int) 1e5 + 10;

using namespace std;





int a[100100];
int b[100100];
int c[100100];
int n;

int calc(vector < int > &v){
    if( v.size() == 0) return 0;
    if( v.size() < 3) return 1;
    int mini = inf;
    int n = v.size();

    for(int i = 0; i < n; i++){
        mini = min(inf, mini);
    }
    int ans = (n + 1)/2;
    if(mini >= ans) return ans;
    return 0;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int ans = 0;

    int sz = 0;
    for(int i = 1; i <= n; i++){
        while(sz > 0 && a[i] < a[c[sz-1]]){
            sz--;
        }
        //cerr << c[sz-1] << endl;
        if( sz > 0 ){
            b[i] = min(min(i, a[i]), b[c[sz-1]] + i - c[sz-1]);
        }
        else {
            b[i] = min(i, a[i]);
        }
        c[sz++] = i;
    }
    sz = 0;
    for(int i = n; i > 0; i--){
        while(sz > 0 && a[i] < a[c[sz-1]]){
            sz--;
        }

        if( sz > 0 ){
            b[i] = min(b[i], min(min(n - i + 1, a[i]), b[c[sz-1]] + c[sz-1] - i));
        }
        else {
            b[i] = min(b[i], n - i + 1);
        }
        c[sz++] = i;
    }
    int maxii = 0;
    for(int i = 1; i <= n; i++){
        maxii = max(maxii, b[i]);
//      cerr<< i << " "<< b[i] << endl;
    }
    cout << maxii << endl;
    return 0;

    for(int i = 1; i < 500; i++){
        for(int j= 1; j<=n; j++){
            int c = min(a[j-1], a[j + 1]);
            if( c >= a[j] ) b[j] = max(a[j] - 1, 0);
            else b[j] = c;
        }
        bool ok = 0;
        for(int j = 1; j <= n; j++){
            a[j] = b[j];
            ok |= (a[j] > 0);
        }
        if( ok ) continue;
        ans++;
        cout<< i << endl;
        return 0;
    }
    vector < int > v;
    int maxi = 0;
    for(int j = 1; j <= n; j++){
        if(a[j] > 0){
            maxi = max(calc(v), maxi);
            v.clear();
        }
        else {
            v.pb( a[j] );
        }
    }
    maxi = max(calc(v), maxi);
    cout << maxi << endl;
    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}