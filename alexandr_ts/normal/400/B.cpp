#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 2e5;
const int INF = 2e9;

int dist[N], poss[N], posg[N];

string s[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> s[i];
    fr(i, n)
        fr(j, m)
            if (s[i][j] == 'S')
                poss[i] = j;
            else if (s[i][j] == 'G')
                posg[i] = j;
    unordered_set <int> st;
    fr(i, n)
        if (posg[i] > poss[i]) {
            cout << -1;
            return 0;
        }
        else
            st.insert(poss[i] - posg[i]);
    cout << st.size();
}