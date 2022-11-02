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
ll v[4444], d[4444], p[4444];
vector < int > ans;
bool ok[4444];
deque < int > st;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i] >> d[i] >> p[i];
    }
    for(int i = 0; i < n; i++){
        if( ok[i]) continue;
        ans.pb( i + 1 );
        int mx = v[i];
        for(int j = i + 1; j < n && mx > 0; j++){
            if( ok[j] ) continue;
            p[j] -= mx;
            if(p[j] < 0){
                st.pb( j );
                ok[j] = 1;
            }
            mx--;
        }
        while(st.size() > 0){
            int pr = st.front();
            st.pop_front();
            for(int j = pr + 1; j < n ; j++){
                if( ok[j] ) continue;
                p[j] -= d[pr];
                if(p[j] < 0){
                    st.pb( j );
                    ok[j] = 1;
                }
            }
        }

    }
    cout << ans.size() << endl;
    for(int i: ans){
        cout << i << " ";
    }
    cout << endl;
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}