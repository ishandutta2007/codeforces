#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void sol(){

    string s;
    cin >> s;
    ll n = s.size();

    deque <char> q;
    vector <char> ans;

    for(auto i : s){
        if(q.empty()){
            q.push_back(i);
        }else{
            if(q.front() % 2 != i % 2){
                while(!q.empty() && q.front() < i){
                    ans.p_b(q.front());
                    q.pop_front();
                }
                if(q.empty())q.push_back(i);
                else ans.p_b(i);
            }else q.push_back(i);
        }
    }

    for(auto i : q)ans.p_b(i);

    for(auto i : ans)cout << i;
    cout << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}