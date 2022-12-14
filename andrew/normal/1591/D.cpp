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
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 6e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

int t[N], n;

void u(int x){
    for(int i = x; i <= n; i += i & -i) t[i]++;
}

int f(int x){
    int r = 0;
    for(int i = x; i > 0; i -= i & -i) r += t[i];
    return r;
}

void solve(){
    cin >> n;
    ll s = 0;
    for(int i = 1; i <= n; i++) t[i] = 0;
    map <int, int> mp;
    int r = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(!mp[x]){
            s += r - f(x);
            u(x);
            r++;
            mp[x] = 1;
        }     
    }
    if(s % 2 == 0 || mp.size() != n){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    // int len = 4;

    // vector <int> p(len);
    // for(int i = 0; i < len; i++) p[i] = i;

    // map <vector <int>, bool> mp;

    // queue <vector <int> > q;

    // q.push(p);
    // mp[p] = 1;

    // while(!q.empty()){
    //     vector <int> xe = q.front();
    //     q.pop();

    //     for(int i1 = 0; i1 < len; i1++)
    //         for(int i2 = 0; i2 < len; i2++) if(i1 != i2)
    //             for(int i3 = 0; i3 < len; i3++) if(i1 != i3 && i2 != i3){
    //                 int a, b, c;
    //                 a = xe[i1], b = xe[i2], c = xe[i3];
    //                 xe[i1] = c;
    //                 xe[i2] = a;
    //                 xe[i3] = b;
    //                 if(mp.find(xe) == mp.end()) {
    //                     mp[xe] = 1;
    //                     q.push(xe);
    //                 }
    //                 xe[i1] = a;
    //                 xe[i2] = b;
    //                 xe[i3] = c;
    //             }

    // }

    // do{
    //     if(mp.find(p) != mp.end()){
    //         for(auto i : p) cout << i << " ";
    //         cout << "\n";
    //         //break;
    //     }
    // }while(next_permutation(all(p)));

    // cout << "OK\n";    

    return 0;
}