#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

int a[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
	int n;
	cin >> n;
    string s;
    cin >> s;
    set <char> st;
    fr(i, s.size())
        st.insert(s[i]);
    int cnt = st.size();

    int ans = INF;
    int cur = 0;

    int tmp = 0;
    while (tmp < cnt) {
        if (!a[s[cur]])
            tmp++;
        a[s[cur]]++;
        cur++;
    }
    ans = cur;
    cur--;
    //cout << a['O'] << a['S'] << a['i'] << endl;
    frab(i, 0, s.size()) {
        a[s[i]]--;
        if (a[s[i]] == 0) {
            cur++;
            while (s[cur] != s[i] && cur < s.size()) {
                if (cur < n)
                    a[s[cur]]++;
                cur++;
            }
            if (cur < n)
                a[s[cur]]++;
            //cur--;
        }
        if (a[s[i]]) {
            // << i << " " << cur << endl;
            ans = min(ans, cur - i);
            //a[s[i]]++;
        }
        else
            break;

    }
    cout << ans;
}