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
bool bylo;
string x;
bool zawiera(string &s) {
        rep(i, x.size()-s.size()+1) {
                if(x.substr(i, s.size())==s) return true;
        }
        return false;
}
void tworz(string &s, int n) {
        if(bylo) return;
        if(s.size()==n) {
                if(!zawiera(s)) {
                        bylo=true;
                        cout << s << '\n';
                }
                return;
        }
        rep(i, 26) {
                char c=i+'a';
                string xd=s+c;
                tworz(xd, n);
        }
}
void solve() {
        bylo=false;
        int n;
        cin >> n >> x;
        int z=1;
        while(!bylo) {
                string p="";
                tworz(p, z);
                ++z;
        }
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}