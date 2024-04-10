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

int p[2020];
int a[2020];
int b[2020];
int n;
vector < pii > v;
vector < pii > cur;
bool used[2020];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];

    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        p[b[i]] = i;
    }
    for(int i = 1; i <= n; i++)
        a[i] = p[a[i]];

    int cnt = 0;
    for(int j = 1; j <= n; j++){
        cur.clear();
        for(int i = j;  ; i++){
            cur.pb( mp(a[i], i) );
            if( a[i] == j ) break;
        }
        sort(all(cur));
        int mi = cur[0].s;
        int pos = cur.size();
        while( pos > 0 ){
            if(cur[pos-1].s >= mi) {
                pos--;
                continue;
            }
            pos--;
            swap(a[cur[pos].s], a[mi]);
            v.pb( mp(cur[pos].s, mi));
            mi = cur[pos].s;
        }
    }
    for(int i = 0; i <v.size(); i++)
        cnt += abs(v[i].f - v[i].s);
    cout << cnt << endl;
    cout << v.size();
    for(int i = 0; i < v.size(); i++){
        printf("\n");
        printf("%d %d", v[i].f , v[i].s);
    }
    printf("\n");

    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}