#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n;
set<int> pos;
int a[maxn];
int L[maxn];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<pii> segments;
    for(int i = 0; i < n; ) {
        int j = i;
        pos.insert(i);
        while(i < n && a[j] == a[i]) i++;
        L[j] = i - j;
        segments.insert(make_pair(-L[j], j));
    }
    int cnt = 0;
    while(segments.size() > 0) {
        ++cnt;
        pii x = *segments.begin();
        segments.erase(segments.begin());
        auto it = pos.lower_bound(x.second);
        if(it == pos.begin()) {
            pos.erase(it);
            continue;
        }
        it--;
        int i = *it;
        it++;
        it++;
        if(it == pos.end()) {
            it--;
            pos.erase(it);
            continue;
        }
        int j = *it;
        it--;
        pos.erase(it);
        if(a[i] == a[j]) {
            segments.erase(make_pair(-L[j], j));
            segments.erase(make_pair(-L[i], i));
            L[i] += L[j];
            segments.insert(make_pair(-L[i], i));
            pos.erase(j);
        }
    }
    cout << cnt << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}