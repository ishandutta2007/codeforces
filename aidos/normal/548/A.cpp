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



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string a;
    int n, k,len;
    cin >> a >> len;
    n = a.size();
    if(n  % len == 0){
        bool ok = 1;
        k = n/len;
        for(int i  = k-1; i<n && ok; i+=k){
                int z = k;
                int j = i;
                string cur = "";
                while(z > 0){
                    cur += a[j];
                    j--;
                    z--;
                }
                j = i - k + 1;
                z = 0;
                //cout << cur << endl;
                while( j <= i){
                    if(cur[z] != a[j]){
                        ok = 0;
                        break;
                    }
                    z++;
                    j++;
                }
        }
        if(ok){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO" << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}