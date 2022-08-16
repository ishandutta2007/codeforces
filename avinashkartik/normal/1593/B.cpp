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

string s;

int o(){
    int f = 0, ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (f == 0 && s[i] == '5') {
            f = 1;
            ans--;
        } else if (f == 1) {
            if (s[i] == '2' || s[i] == '7') {
                f = 2;
                break;
            }
        }
        ans++;
    }
    if (f != 2) ans = 25;
    return ans;
}

int e(){
    int f = 0, ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (f == 0 && s[i] == '0') {
            f = 1;
            ans--;
        } else if (f == 1) {
            if (s[i] == '0' || s[i] == '5') {
                f = 2;
                break;
            }
        }
        ans++;
    }
    if (f != 2) ans = 25;
    return ans;
}

void solve() {
    cin >> s;
    deb1(min(o(), e()))
}

int main() {
    GODSPEED;
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        solve();
    }
}