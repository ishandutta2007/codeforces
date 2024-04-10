#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
int mx[maxn];
int mi[maxn];
int pos[maxn];
int dx[]= {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int T;
int u[maxn];
int get_mex() {
    T++;
    for(int i = 0; i < n; i++) {
        u[a[i]] = T;
    }
    int pos = 0;
    while(u[pos] == T) pos++;
    return pos;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans;

    int pos = n-1;
    while(pos >= 0) {
        if(a[pos] == pos) {
            pos--;
            continue;
        }
        int cur = get_mex();
        if(cur >= pos + 1) {
            int j = 0;
            while(a[j] != pos) {
                j++;
            }
            ans.emplace_back(j + 1);
            a[j] = cur;
        } else if(cur == pos) {
            a[pos] = cur;
            ans.emplace_back(pos+1);
        } else {
            a[cur] = cur;
            ans.emplace_back(cur+1);
        }
    }
    cout << ans.size() << "\n";
    for(int to: ans) cout << to << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}