#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e6+7;
int ma[LIM][21];
int cnt(int l, int r) {
    int o=lg(r-l+1);
    return max(ma[l][o], ma[r-(1<<o)+1][o]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i, n) {
        int a;
        cin >> a;
        ma[a][0]=a;
    }
    for(int j=1; j<21; ++j) {
        rep(i, LIM) {
            ma[i][j]=max(ma[i][j-1], ma[min(LIM-1, i+(1<<j-1))][j-1]);
        }
    }
    int ans=0;
    for(int i=1; i<LIM; ++i) if(ma[i][0]) {
        for(int p=i; p<LIM; p+=i) {
            ans=max(ans, cnt(p, min(p+i, LIM)-1)%i);
        }
    }
    cout << ans << '\n';
}