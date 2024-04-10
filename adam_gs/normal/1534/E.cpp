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
const int LIM=507, INF=1e9+7;
vector<int>V[LIM], sciezka;
int odl[LIM], n, k, lst[LIM], odw[LIM];
int main() {
        cin >> n >> k;
        rep(i, n+1) {
                rep(j, n+1) {
                        int a=j-i+k;
                        if(a%2==1 || abs(i-j)>k) continue;
                        a/=2;
                        int b=k-a;
                        if(i<b || a+i>n) continue;
                        V[i].pb(j);
                }
        }
        rep(i, n) odl[i+1]=INF;
        queue<int>q;
        q.push(0);
        while(!q.empty()) {
                int p=q.front(); q.pop();
                for(auto i : V[p]) if(odl[i]==INF) {
                        odl[i]=odl[p]+1;
                        lst[i]=p;
                        q.push(i);
                }
        }
        if(odl[n]==INF) {
                cout << -1 << endl;
                return 0;
        }
        int p=n;
        while(p!=0) {
                sciezka.pb(p);
                p=lst[p];
        }
        reverse(all(sciezka));
        int po=0, ans=0;
        for(auto i : sciezka) {
                int a=i-po+k; a/=2;
                int b=k-a;
                vector<int>jakie;
                rep(j, n) {
                        if(a && !odw[j]) {
                                jakie.pb(j+1);
                                --a;
                        }
                        if(b && odw[j]) {
                                jakie.pb(j+1);
                                --b;
                        }
                }
                for(auto j : jakie) odw[j-1]^=1;
                cout << "? ";
                for(auto j : jakie) cout << j << " ";
                cout << endl;
                int x;
                cin >> x;
                ans^=x;
                po=i;
        }
        cout << "! " << ans << endl;
}