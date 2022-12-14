#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 3000 + 5;
const ll inf = 1e9;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s) {cout << s << endl; exit(0);}

ll dp[N][2];

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1), b, l(n + 1);
    int k = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> l[i];
        if(l[i] == 0){
            b.p_b(a[i]);
        }
    }

    sort(all(b));
    int s = 0;
    for(int i = 1; i <= n; i++){
        if(l[i] == 0){
            a[i] = b.back();
            b.pop_back();
        }
        s += a[i];
        if(s < 0)k = i;
    }
    for(int i = 1; i <= n; i++)cout << a[i] << " ";
    cout << "\n";
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);    

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){ 
        solve();
    }
  
    return 0;
}