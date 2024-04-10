#include <bits/stdc++.h>
using namespace std;
 
const bool ready = [](){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(12);
    return true;
}();
 
using ld=long double;
const ld PI = acos((ld)-1);
using ll= long long;
#define int ll
#define all(v) (v).begin(), (v).end()
#define fori(n) for(int i=0; i<int(n); i++)
 
#define cini(i) int i; cin>>i;
#define cins(s) string s; cin>>s;
#define cind(d) ld d; cin>>d;
#define cinai(a,n) vi a(n); fori(n) { cin>>a[i]; }
#define cinas(s,n) vs s(n); fori(n) { cin>>s[i]; }
#define cinad(a,n) vd a(n); fori(n) { cin>>a[i]; }
 
using pii= pair<int, int>;
using pdd= pair<ld, ld>;
using vd= vector<ld>;
using vb= vector<bool>;
using vi= vector<int>;
using vvi= vector<vi>;
using vs= vector<string>;
 
#define endl "\n"
 
/**
 * There might be a middle segment we cannot sort.
 * Off-by-one-forces.
 */
void solve() {
    cini(n);
    cini(x);
    cinai(a,n);
 
    if(x==1) {
        cout<<"YES"<<endl;
        return;
    }
 
    int l=max(0LL, n-x); // leftmost element of middle segment 0 based
    int r=min(n-1, x-1);  // rightmost element of middle segment 0 based
 
    vi aa=a;
    sort(all(aa));
    for(int i=l; i<=r; i++)  {
        if(aa[i]!=a[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }
 
    cout<<"YES"<<endl;
}
 
signed main() {
    cini(t);
    while(t--)
        solve();
}