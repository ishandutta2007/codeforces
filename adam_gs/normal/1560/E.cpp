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
void solve() {
        string x;
        cin >> x;
        string s=x;
        int ile=0;
        map<char,int>mp;
        rep(i, x.size()) {
                if(!mp[x[i]]) ++ile;
                mp[x[i]]=1;
        }
        string ans="";
        int sum=0;
        rep(i, ile) {
                char p=x[x.size()-1];
                int a=0;
                rep(j, x.size()) if(x[j]==p) ++a;
                if(a%(ile-i)!=0) {
                        cout << -1 << '\n';
                        return;
                }
                sum+=a/(ile-i);
                ans+=p;
                string tmp="";
                rep(j, x.size()) if(x[j]!=p) tmp+=x[j];
                x=tmp;
        }
        reverse(all(ans));
        int l=0;
        string jaki="";
        rep(i, sum) jaki+=s[i];
        rep(j, ile) {
                string akt="";
                rep(i, jaki.size()) {
                        akt+=s[l+i];
                }
                l+=jaki.size();
                if(akt!=jaki) {
                        cout << -1 << '\n';
                        return;
                }
                string tmp="";
                for(auto i : jaki) if(i!=ans[j]) tmp+=i;
                jaki=tmp;
        }
        rep(i, sum) cout << s[i];
        cout << " " << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}