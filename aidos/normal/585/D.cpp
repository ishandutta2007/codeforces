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
int l[35][3];
char c[] = {'L', 'M', 'W'};
int ans[5];

map < pair < pii, int>, pii > M;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++)
            cin >> l[i][j];
    }
    
    if( n < 15){
        int cur = 1;
        for(int i = 0; i < n; i++)
            cur *= 3;
        int tt = -(int) 1e9;
        int cur_mask = -1;
        for(int i = 0; i < cur; i++){
            memset(ans, 0, sizeof ans);
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 3; k++)
                    ans[k] += l[j][k];
            }
            int mask=i;
            for(int j = 0; j < n; j++){
                ans[mask % 3] -= l[j][mask % 3];
                mask /= 3;
            }
            if(ans[0] == ans[1] && ans[0] == ans[2]) {
                if( tt < ans[1]){
                    tt = ans[1];
                    cur_mask = i;
                }
            }
        }
        if( cur_mask == -1) cout << "Impossible"<<endl;
        else {
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 3; k++){
                    if( cur_mask % 3==k) continue;
                    cout << c[k];
                }
                cout << endl;
                cur_mask /= 3;
            }
        }
        return 0;
    }
    int part = n;
    n = n/2;
        int cur = 1;
        for(int i = 0; i < n; i++)
            cur *= 3;
        int tt = -(int) 1e9;
        ll cur_mask = -1;
        for(int i = 0; i < cur; i++){
            memset(ans, 0, sizeof ans);
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 3; k++)
                    ans[k] += l[j][k];
            }
            int mask=i;
            for(int j = 0; j < n; j++){
                ans[mask % 3] -= l[j][mask % 3];
                mask /= 3;
            }
            if(M.count(mp(mp(ans[1] - ans[0], ans[2] - ans[0]), ans[2] - ans[1]))  == 0 || M[mp(mp(ans[1] - ans[0], ans[2] - ans[0]), ans[2] - ans[1]) ].f < ans[0])
                M[mp(mp(ans[1] - ans[0], ans[2] - ans[0]), ans[2] - ans[1])] = mp(ans[0], i);
        }
        int cur2 = 1;
        for(int i = 0; i < part - n; i++)
            cur2 *= 3;
        for(int i = 0; i < cur2; i++){
            memset(ans, 0, sizeof ans);
            for(int j = n; j < part; j++){
                for(int k = 0; k < 3; k++)
                    ans[k] += l[j][k];
            }
            int mask=i;
            for(int j = n; j < part; j++){
                ans[mask % 3] -= l[j][mask % 3];
                mask /= 3;
            }
            if(M.count(mp(mp(ans[0] - ans[1], ans[0] - ans[2]), ans[1] - ans[2])) > 0){
                if( tt < ans[0] + M[mp(mp(ans[0] - ans[1], ans[0] - ans[2]), ans[1] - ans[2])].f){
                    tt = ans[0] + M[mp(mp(ans[0] - ans[1], ans[0] - ans[2]), ans[1] - ans[2])].f;
                    cur_mask = M[mp(mp(ans[0] - ans[1], ans[0] - ans[2]), ans[1] - ans[2])].s + i * 1ll*cur;
                }
            }
        }
        if(cur_mask == -1){
            cout << "Impossible\n";
        }
        else {
            for(int j = 0; j < part; j++){
                for(int k = 0; k < 3; k++){
                    if( cur_mask % 3==k) continue;
                    cout << c[k];
                }
                cout << endl;
                cur_mask /= 3;
            }
        }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}