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
const ll MAXN = 1123456;
const ll inf = 1e8;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

set <ll> v[26];
bool f[26], ft[26];
ll used[26], bad = 0;

void go(ll x, ll pr){
    if(used[x] == 1){
        bad = 1;
        return;
    }
    if(used[x] == 2)return;
    used[x] = 1;
    for(auto to : v[x])if(to != pr)go(to, x);
    used[x] = 2;
}

vector <ll> order;

string answer;

void top_sort(ll x){
    if(f[x])return;
    f[x] = 1;
    for(auto to : v[x])top_sort(to);
    order.p_b(x);
}

void dfs(ll x){
    if(ft[x])return;
    answer += char(x + 'a');
    ft[x] = 1;
    for(auto to : v[x])dfs(to);
}




int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--){
        string s;
        bad = 0;
        for(int i = 0; i < 26; i++){
            f[i] = used[i] = ft[i] = 0;;
            v[i].clear();
        }
        cin >> s;
        for(int i = 1; i < sz(s); i++){
            v[s[i - 1] - 'a'].insert(s[i] - 'a');
            v[s[i] - 'a'].insert(s[i - 1] - 'a');
        }

        for(int i = 0; i < 26; i++)if(sz(v[i]) > 2)bad = 1;

        for(int i = 0; i < 26; i++)if(!used[i]){
            go(i, 0);
        }

        order.clear();
        answer.clear();
        if(bad){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < 26; i++)if(!f[i])top_sort(i);
        for(auto i : order)dfs(i);
        cout << answer << "\n";
    }

    return 0;
}