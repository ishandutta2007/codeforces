#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

vector <ll> v[MAXN],va;
string s2,s3;
set <ll> s,s1;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll d;
    cin >> n >> m >> a1 >> b1 >> d;
    for(i = 1; i <= a1; i++){
        cin >> x;
        s.insert(x);
    }
    for(i = 1; i <= b1; i++){
        cin >> x;
        s1.insert(x);
    }
    ll q;
    cin >> q;
    set <ll> :: iterator it, it1;
    while(q--){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            cout << abs(y2 - y1) << endl;
            continue;
        }
        if(y1 > y2){
            swap(x1, x2);
            swap(y1, y2);
        }
        ans = 1e18;
        it = s.upper_bound(y1);
        if(it != s.end()){
               // cout << abs(x2 - x2) + y2 - y1 + 2 * max(*it - y2, 0ll) << " 1\n";
            ans = min(ans, abs(x2 - x1) + y2 - y1 + 2 * max(0ll, *it - y2));
        }
        it = s.upper_bound(y1);
        if(s.size() && it != s.begin()){
            --it;
               // cout << abs(x2 - x2) + y2 - y1 + 2 * max(y1 - *it, 0ll) << " 2\n";
            ans = min(ans, abs(x2 - x1) + y2 - y1 + 2 * max(y1 - *it, 0ll));
        }
        it = s1.upper_bound(y1);
        ll k = abs(x2 - x1) / d;
        if(abs(x2 - x1) % d)k++;
        if(it != s1.end()){
               // cout << k + y2 - y1 + 2 * max(*it - y2, 0ll) << " 3\n";
            ans = min(ans, k + y2 - y1 + 2 * max(0ll, *it - y2));
        }
        it = s1.upper_bound(y1);
        if(s1.size() && it != s1.begin()){
            --it;
               // cout << k + y2 - y1 + 2 * max(y1 - *it, 0ll) << " 4\n";
            ans = min(ans, k + y2 - y1 + 2 * max(y1 - *it, 0ll));
        }
        cout << ans << endl;
    }


    return 0;
}
/*
5 6 0 2 3
2
5
3
1 1 5 6
1 3 5 4
3 3 5 3
*/