#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

int del0(int x) {
    char ans[10];
    fill(ans, ans + 10, 0);
    int cur = 0;
    while (x > 0) {
        if (x % 10)
            ans[cur++] = (char)('0' + x % 10);
        x /= 10;
    }
    reverse(ans, ans + cur);
    return atoi(ans);
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    set <char> st;
    fr(i, s.size())
        st.insert(s[i]);
    if (st.size() < n) {
        cout << "NO";
        return 0;
    }
    st.clear();
    cout << "YES" << endl;
    int cnt = 0;
    string cur;
    fr(i, s.size()) {
        if ((!st.count(s[i]) && cur[0] != s[i] || i == (int)s.size() - 1) && i && s[i] != s[i - 1] && cnt < n - 1) {
            cout << cur << endl;
            st.insert(cur[0]);
            cur = "";
            cnt++;
        }
        cur += s[i];
    }
    cout << cur;
}