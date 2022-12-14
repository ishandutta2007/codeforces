#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

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

void inc(string &a, string &b){
    if(b[1] == '9'){
        b[1] = '0';
        if(b[0] == '5'){
            b[0] = '0';
            if(a[1] == '9'){
                a[1] = '0';
                a[0]++;
            }else a[1]++;
            if(a == "24")a = "00";
        }else b[0]++;
    }else b[1]++;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll a, b;
    char sosat_akel;
    cin >> a >> sosat_akel >> b;
    stringstream ss;
    ss << a;
    string ra, rb;
    ss >> ra;
    ss.clear();
    ss << b;
    ss >> rb;

    if(ra.size() == 1)ra = "0" + ra;
    if(rb.size() == 1)rb = "0" + rb;

    inc(ra, rb);
    while(1){
        string ca, cb;
        ca = ra, cb = rb;
        reverse(all(cb));
        if(ca == cb){
            cout << ra << ":" << rb << "\n";
            exit(0);
        }
        inc(ra, rb);
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}