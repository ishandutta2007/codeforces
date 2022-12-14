#include <bits/stdc++.h>

//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1123456;
const int N = 1e5 + 3;
const int M = pw(10);
const int inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void vivod(queue <int> &q){
    if(q.empty())return;
    int x = q.front();
    q.pop();
    vivod(q);
    cout << x << " ";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    queue <int> q;

    map <int, bool> f;

    while(n--){
        int x;
        cin >> x;
        if(f[x])continue;
        f[x] = 1;
        q.push(x);
        if(q.size() == k + 1){
            int Val = q.front();
            q.pop();
            f[Val] = 0;
        }
    }

    cout << q.size() << "\n";
    vivod(q);
    cout << "\n";

    return 0;
}