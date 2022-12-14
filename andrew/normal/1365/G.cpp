#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5 + 2;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll ask(vector <int> numbers){
    if(numbers.empty())return 0;
    cout << "? " << sz(numbers);
    for(auto i : numbers) cout << " " << i;
    cout << endl;
    ll x;
    cin >> x;
    return x;
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

//    #ifdef LOCAL
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif // LOCAL

    vector <int> musks;

    for(int i = 0; i < pw(13); i++)if(__builtin_popcount(i) == 6){
        musks.p_b(i);
    }

    int n;
    cin >> n;

    vector <ll> values(13);

    for(int i = 0; i < 13; i++){
        vector <int> pozitions;
        for(int j = 0; j < n; j++)if((pw(i) & musks[j]) == 0)pozitions.p_b(j + 1);
        values[i] = ask(pozitions);
    }

    cout << "!";

    for(int i = 0; i < n; i++){
        ll answer = 0;
        for(int j = 0; j < 13; j++)if((pw(j) & musks[i]))answer |= values[j];
        cout << " " << answer;
    }

    cout << endl;


    return 0;
}