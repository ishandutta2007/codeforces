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
const ll M = 2e5;
const int N = 1e7;
const int inf = 1e8;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}



void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int uk = 0;
    while(uk + 1 < n){
        if(s[uk] == '1' && s[uk + 1] == '1'){
            break;
        }
        uk++;
    }

    if(s[uk] == '1' && s[uk + 1] == '1'){
        for(int i = uk; i + 1 < n; i++){
            if(s[i] == '0' && s[i + 1] == '0'){
                fout("No");
            }
        }
        fout("Yes");
    }else{
        fout("Yes");
    }
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}