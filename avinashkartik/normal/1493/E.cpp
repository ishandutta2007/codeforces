#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;
string a, b;

void solve() {
    cin >> n >> a >> b;
    if (n == 1 || a == b) {
        deb1(b)
        return;
    }
    string c = b;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            continue;
        } else {
            int fa = 1, fb = 0;
            for (int j = i + 1; j < n; j++) fa &= (a[j] - '0');
            for (int j = i + 1; j < n; j++) fb |= (b[j] - '0');
            if (i == 0) {
                for (int j = i; j < n; j++) c[j] = '1';
            } else if (fa == 0 || fb == 1) {
                c[n - 1] = '1';
            } 
            break;
        }
    }
    deb1(c)
}

int main() {
    GODSPEED;
    int test = 1;
    // cin >> test;
    for (int i = 1; i <= test; i++) {
        solve();
    }
}