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
        int n;
        cin >> n;
        int T[n], uzyte[n+1], jakie[n];
        rep(i, n) {
                cin >> T[i];
                uzyte[i+1]=jakie[i]=0;
        }
        jakie[0]=T[0];
        uzyte[T[0]]=1;
        for(int i=1; i<n; ++i) if(T[i]!=T[i-1]) {
                uzyte[T[i]]=1;
                jakie[i]=T[i];
        }
        int akt=1;
        rep(i, n) {
                if(jakie[i]) cout << jakie[i] << " ";
                else {
                        while(uzyte[akt]) ++akt;
                        cout << akt << " ";
                        ++akt;
                }
        }
        cout << '\n';
        priority_queue<int>q;
        akt=1;
        rep(i, n) {
                if(jakie[i]) {
                        while(akt<=jakie[i]) {
                                if(!uzyte[akt]) q.push(akt);
                                ++akt;
                        }
                        cout << jakie[i] << " ";
                } else {
                        cout << q.top() << " ";
                        q.pop();
                }
        }
        cout << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}