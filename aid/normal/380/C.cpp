#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int l[MAXN], cl[MAXN], fen[MAXN], ans[MAXN];
pair<int, int> q[MAXN], ev[2 * MAXN];
string s;
stack<int> st;

void add(int i, int x) {
    for(; i < MAXN; i |= i + 1)
        fen[i] += x;
}

int get(int i) {
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res += fen[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++)
        if(s[i] == '(')
            st.push(i + 1);
        else if(st.empty())
            l[i] = 0;
        else {
            l[i] = st.top();
            st.pop();
        }
    for(int i = 0; i < n; i++) {
        cl[i + 1] = cl[i];
        if(s[i] == ')')
            cl[i + 1]++;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> q[i].first >> q[i].second;
        q[i].first--;
        ev[2 * i] = make_pair(q[i].first, i);
        ev[2 * i + 1] = make_pair(q[i].second, i);
    }
    sort(ev, ev + 2 * m);
    int j = 0;
    for(int i = 0; i < 2 * m; i++) {
        while(j + 1 <= ev[i].first) {
            if(s[j] == ')')
                add(l[j], 1);
            j++;
        }
        if(ev[i].first == q[ev[i].second].first)
            ans[ev[i].second] = get(ev[i].first) - cl[ev[i].first];
        else
            ans[ev[i].second] += cl[ev[i].first] - get(q[ev[i].second].first);
    }
    for(int i = 0; i < m; i++)
        cout << 2 * ans[i] << '\n';
    return 0;
}