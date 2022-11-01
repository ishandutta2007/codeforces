#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    int cnt = 0;
    frab(i, 1, s.size())
        cnt += (s[i] == '.' && s[i - 1] == '.');
    fr(i, q) {
        int t;
        char c;
        cin >> t >> c;
        t--;
        if (!(isalpha(s[t]) xor isalpha(c))) {
            cout << cnt << endl;
            continue;
        }
        if (isalpha(s[t])) {
            s[t] = c;
            if (t > 0 && s[t - 1] == '.')
                cnt++;
            if (t < n - 1 && s[t + 1] == '.')
                cnt++;
        }
        else {
            s[t] = c;
            if (t > 0 && s[t - 1] == '.')
                cnt--;
            if (t < n - 1 && s[t + 1] == '.')
                cnt--;
        }
        cout << cnt << endl;
    }
}