#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
const int LIM=1e5+7;
const ll MOD=1e9+7;
vector<int>V[LIM], S[LIM], spojne[LIM];
int odw[LIM], nr[LIM], l;
ll T[LIM], mi[LIM], ile[LIM];
stack<int>st;
void DFS(int x) {
        odw[x]=1;
        for(auto i : V[x]) if(!odw[i]) DFS(i);
        st.push(x);
}
void DFS2(int x) {
        nr[x]=l;
        spojne[l].pb(x);
        for(auto i : S[x]) if(!nr[i]) DFS2(i);
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n;
        cin >> n;
        rep(i, n) cin >> T[i];
        int m;
        cin >> m;
        rep(i, m) {
                int a, b;
                cin >> a >> b; --a; --b;
                V[a].pb(b);
                S[b].pb(a);
        }
        rep(i, n) if(!odw[i]) DFS(i);
        while(!st.empty()) {
                int p=st.top(); st.pop();
                if(nr[p]) continue;
                ++l;
                DFS2(p);
        }
        ll ans1=0, ans2=1;
        rep(i, l) {
                mi[i+1]=MOD;
                for(auto j : spojne[i+1]) {
                        if(T[j]<mi[i+1]) {
                                mi[i+1]=T[j];
                                ile[i+1]=0;
                        }
                        if(T[j]==mi[i+1]) ++ile[i+1];
                }
                ans1+=mi[i+1];
                ans2=(ans2*ile[i+1])%MOD;
        }
        cout << ans1 << " " << ans2 << '\n';
}