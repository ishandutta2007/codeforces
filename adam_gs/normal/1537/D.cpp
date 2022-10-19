#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
bool potega(int p, int n) {
        while(n%p==0) n/=p;
        return n==1;
}
void solve() {
        int n;
        cin >> n;
        if(n%2==0 && (!potega(2, n) || potega(2, n) && potega(4, n))) {
                cout << "Alice\n";
        } else {
                cout << "Bob\n";
        }
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}