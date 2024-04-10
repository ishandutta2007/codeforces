#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define c(n) (n * (n - 1) / 2)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 10001;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int t[N + 2];

void u(int pos, int val){
    for(; pos <= N; pos += pos & -pos)t[pos] += val;
}

int res = 0;

int f(int pos){
    res = 0;
    for(; pos > 0; pos -= pos & -pos)res += t[pos];
    return res;
}

vector <int> v[N + 5];

struct line{
    int x, y, x1, y1;
    bool tp;
};

bool cmp(line &l, line &r){
    return (l.y < r.y);
}

bool intersects(line a, line b){
    if(a.tp == b.tp)return 0;
    if(a.tp == 0){
        if(a.x <= b.x && b.x <= a.x1 && b.y <= a.y && a.y <= b.y1)return 1;
        return 0;
    }else{
        swap(a, b);
        if(a.x <= b.x && b.x <= a.x1 && b.y <= a.y && a.y <= b.y1)return 1;
        return 0;
    }
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <line> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y >> a[i].x1 >> a[i].y1;
        a[i].x += 5001;
        a[i].x1 += 5001;
        a[i].y += 5001;
        a[i].y1 += 5001;
        if(a[i].x > a[i].x1)swap(a[i].x, a[i].x1);
        if(a[i].y > a[i].y1)swap(a[i].y, a[i].y1);
        if(a[i].y == a[i].y1)a[i].tp = 0;else a[i].tp = 1;
    }

    sort(all(a), cmp);

    ll ans = 0;

    int val;

    for(int i = 0; i < n; i++)if(!a[i].tp){
        int uk = a[i].y;
        for(int j = 0; j < n; j++){

            while(uk < a[j].y){
                for(int val : v[uk]){
                    u(val, -1);
                }
                v[uk].clear();
                uk++;
            }

            if(intersects(a[i], a[j])){
                u(a[j].x, 1);
                v[a[j].y1].p_b(a[j].x);
            }else if(a[j].y > a[i].y){
                val = f(a[j].x1) - f(a[j].x - 1);
                ans += c(val);
            }

        }
        while(uk <= N){
            for(int val : v[uk]){
                u(val, -1);
            }
            v[uk].clear();
            uk++;
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}