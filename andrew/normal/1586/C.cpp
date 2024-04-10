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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1123456;
const int M = pw(16);
const long long mod = 1e9 + 7;
const int N = 2e5;
const ll inf = 1e16;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <vector <int> > a(n + 2, vector <int>(m + 2, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c == 'X'){
                a[i][j] = 1;
            }
        }
    }

    vector <int> b(m + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i + 1][j] && a[i][j + 1]){
                b[j] = 1;
            }
        }
    }

    for(int j = 1; j <= m; j++){
        b[j] += b[j - 1];
    }

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;
        string ans = "YES";
        if(b[r - 1] - b[l - 1] > 0){
            ans = "NO";
        }
        cout << ans << "\n";
    }

    return 0;
}