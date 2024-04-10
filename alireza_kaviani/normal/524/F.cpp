#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

int n , diff , valid[MAXN] , ps[MAXN] , mnR[MAXN];
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> s; n = SZ(s);
    for(int i = 0 ; i < n ; i++){
        ps[i + 1] = ps[i] + (s[i] == '(' ? 1 : -1);
    }
    mnR[n] = ps[n];
    for(int i = n - 1 ; i >= 0 ; i--){
        mnR[i] = min(mnR[i + 1] , ps[i]);
    }
    int mn = MOD;
    for(int i = 0 ; i < n ; i++){
        mn = min(mn , ps[i]);
        int val = min(mnR[i + 1] - ps[i] , mn + ps[n] - ps[i]);
        if(val >= min(0 , ps[n])){
            valid[i] = 1;
        }
    }
    int res = -1;
    vector<int> SA = sort_cyclic_shifts(s);
    for(int i : SA){
        if(valid[i]){
            res = i;
            break;
        }
    }
    assert(res != -1);
    string ans = "";
    for(int i = 0 ; i < -ps[n] ; i++){
        ans.push_back('(');
    }
    for(int i = res ; i < n ; i++){
        ans.push_back(s[i]);
    }
    for(int i = 0 ; i < res ; i++){
        ans.push_back(s[i]);
    }
    for(int i = 0 ; i < ps[n] ; i++){
        ans.push_back(')');
    }
    cout << ans << endl;

    return 0;
}
/*

*/