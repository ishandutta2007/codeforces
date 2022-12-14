#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e7 + 5;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int ans[N], d[N];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(ans, ans + N, -1);

    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            d[j] += i;
            if(d[j] > N)d[j] = N;
        }
        if(d[i] < N && ans[d[i]] == -1){
            ans[d[i]] = i;
        }
    }

    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }

    return 0;
}