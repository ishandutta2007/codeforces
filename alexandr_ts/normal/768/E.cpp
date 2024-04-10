#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
const ll INF = 2e15 + 10;
int s[N];

map <pair <ll, ll>, int> m;

int calc(int s, ll mask) {
    //cout << s << " " << mask << endl;
    if (m.count(mp(s, mask))) return m[mp(s, mask)];
    vector <int> gr;
    frab(i, 1, s + 1)
        if (mask & (1 << (i - 1)))
            gr.push_back(calc(s - i, mask ^ (1 << (i - 1))));
    sort(gr.begin(), gr.end());
    gr.resize(unique(gr.begin(), gr.end()) - gr.begin());
    int mex = gr.size();
    fr(i, gr.size())
        if (i != gr[i]) {
            mex = i;
            break;
        }
    m[mp(s, mask)] = mex;
    return mex;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= calc(s[i], (1ll << s[i]) - 1);
        //cout << calc(s[i], (1ll << s[i]) - 1) << endl;
    }
    if (ans == 0)
        cout << "YES";
    else
        cout << "NO";
}