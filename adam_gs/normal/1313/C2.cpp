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
const int LIM=5e5+7;
ll T[LIM], n, lewo[LIM], prawo[LIM];
void solve() {
        cin >> n;
        rep(i, n) cin >> T[i];
        stack<int>q;
        rep(i, n) {
                while(!q.empty() && T[q.top()]>=T[i]) q.pop();
                if(!q.empty()) lewo[i]=lewo[q.top()]+(i-q.top())*T[i];
                else lewo[i]=(i+1)*T[i];
                q.push(i);
        }
        while(!q.empty()) q.pop();
        for(int i=n-1; i>=0; --i) {
                while(!q.empty() && T[q.top()]>=T[i]) q.pop();
                if(!q.empty()) prawo[i]=prawo[q.top()]+(q.top()-i)*T[i];
                else prawo[i]=(n-i)*T[i];
                q.push(i);
        }
        ll p=-1, ans=-1;
        rep(i, n) if(ans<lewo[i]+prawo[i]-T[i]) {
                ans=lewo[i]+prawo[i]-T[i];
                p=i;
        }
        for(int i=p-1; i>=0; --i) T[i]=min(T[i], T[i+1]);
        for(int i=p+1; i<n; ++i) T[i]=min(T[i], T[i-1]);
        rep(i, n) cout << T[i] << " ";
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        while(_--) solve();
}