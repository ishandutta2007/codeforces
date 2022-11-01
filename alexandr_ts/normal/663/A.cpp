#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

int Num(string s) {
    ll ans = 0;
    fr(i, s.size())
        ans = ans * 10 + s[i] - '0';
    return ans;
}

bool Norm(int a, int b, int num, int sum) {
    if (sum > a * num - b) return false;
    if (sum < a - b * num) return false;
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a = 1, b = 0;
    string s, t;
    getline(cin, s);

    vector <int> sg;
    sg.pb(1);

    fr(i, s.size())
        if (s[i] == '-')
            b++, sg.pb(-1);
        else if (s[i] == '+')
            a++, sg.pb(1);

    fr(i, s.size())
        if (isdigit(s[i]))
            t += s[i];
    int num = Num(t);

    //cout << a << " " << b << " " << num << endl;

    vector <int> ans;
    int sum = num;
    fr(i, sg.size()) {
        //cout << a << " " << b << " " << sum << endl;
        if (!Norm(a, b, num, sum)) {
            cout << "Impossible";
            return 0;
        }
        bool fnd = false;
        frab(j, 1, num + 1) {
            if (sg[i] == 1) {
                if (Norm(a - 1, b, num, sum - j)) {
                    sum -= j;
                    ans.pb(j);
                    a--;
                    fnd = true;
                    break;
                }
            }
            else {
                if (Norm(a, b - 1, num, sum + j)) {
                    sum += j;
                    b--;
                    ans.pb(j);
                    fnd = true;
                    break;
                }
            }
        }
        if (!fnd) {
            cout << "Impossible";
            return 0;
        }
    }

    int cur = 0;
    cout << "Possible" << endl;
    fr(i, s.size())
        if (s[i] == '?')
            cout << ans[cur++];
        else
            cout << s[i];


}