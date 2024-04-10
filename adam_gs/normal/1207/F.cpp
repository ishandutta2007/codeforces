#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e5+7, SQ=700;
int T[LIM], ans[SQ][SQ];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t==1) {
            for(int i=1; i<SQ; ++i) ans[x%i][i]+=y;
            T[x]+=y;
        } else {
            if(x<SQ) {
                cout << ans[y][x] << '\n';
            } else {
                int sum=0;
                for(int i=y; i<LIM; i+=x) {
                    sum+=T[i];
                }
                cout << sum << '\n';
            }
        }
    }
}