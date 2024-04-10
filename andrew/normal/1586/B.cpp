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

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> s(n + 1);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        s[b]++;
    }
    int pos = -1;
    for(int i = 1; i <= n; i++)if(!s[i]){
        pos = i;
        break;
    }
    for(int i = 1; i <= n; i++)if(i != pos){
        cout << i << " " << pos << "\n";
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}