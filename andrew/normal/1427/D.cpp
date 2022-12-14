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
const int inf = 1e8;
const ll mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    vector <vector <int> > ans;
    vector <int> b(n + 1);
    bool f = 0;
    for(int i = n - 1; i > 0; i--){
        int pos = -1, pos1 = -1;
        for(int j = 1; j <= n; j++){
            if(a[j] == n){
                pos = j;
            }
            if(a[j] == i){
                pos1 = j;
            }
        }
        vector <int> res;
        int t = n - i;
        if(pos <= pos1){
            if(pos - t + f)res.p_b(pos - t + f);
            res.p_b(t - f);
            if(f){
                res.p_b(1);
                if(pos1 - pos - 1)res.p_b(pos1 - pos - 1);
                if(n != pos1)res.p_b(n - pos1);
            }else{
                res.p_b(pos1 - pos);
                if(n != pos1)res.p_b(n - pos1);
            }
            f = 0;
        }else{
            if(pos1 != 1)res.p_b(pos1 - 1);
            if(pos - pos1 - (t - f - 1))res.p_b(pos - pos1 - (t - f - 1));
            res.p_b(t - f);
            if(f){
                res.p_b(1);
                if(n - pos - 1)res.p_b(n - pos - 1);
            }else{
                if(n - pos)res.p_b(n - pos);
            }
            f = 1;
        }
        int uk = n, uk1 = 1;
        reverse(all(res));
        for(auto i : res){
            for(int j = uk - i + 1; j <= uk; j++)b[uk1++] = a[j];
            uk -= i;
        }
        a = b;
        reverse(all(res));
        ans.p_b(res);
    }
    if(f){
        vector <int> res;
        res.p_b(n - 1);
        res.p_b(1);
        ans.p_b(res);
    }

    cout << sz(ans) << "\n";
    for(auto i : ans){
        cout << sz(i);
        for(auto j : i)cout << " " << j;
        cout << "\n";
    }

    return 0;
}