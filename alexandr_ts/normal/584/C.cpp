#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll N = 2e5 + 1;
const ll M = 211;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MOD = 1e9 + 7;

int a[N];
char ans[N];

bool check(int lft, int t1, int t2, int sum) {
    if (sum > t1 + t2 || max(t1, t2) > lft || sum < (abs(t1 - t2)))
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n, t1, t2;
    cin >> n >> t1;
    t2 = t1;
    string s1, s2;
    cin >> s1 >> s2;
    int sum = 0;
    fr(i, n)
        if (s1[i] != s2[i]) {
            a[i] = 1;
            sum++;
        }
    if (sum > t1 + t2 || max(t1, t2) > n) {
        cout << -1;
        return 0;
    }
    fr(i, n) {
        //cout << t1 << " " << t2 << " " << sum << endl;
        if (a[i]) {
            sum--;
            if (check(n - i - 1, t1 - 1, t2, sum)) {
                ans[i] = s2[i];
                t1--;
            }
            else if (check(n - i - 1, t1, t2 - 1, sum)) {
                ans[i] = s1[i];
                t2--;
            }
            else if (check(n - i - 1, t1 - 1, t2 - 1, sum)) {
                if (s1[i] != 'z' && s2[i] != 'z')
                    ans[i] = 'z';
                if (s1[i] != 'a' && s2[i] != 'a')
                    ans[i] = 'a';
                if (s1[i] != 'b' && s2[i] != 'b')
                    ans[i] = 'b';
                t1--;
                t2--;
            }
        }
        else if (check(n - i - 1, t1 - 1, t2 - 1, sum)) {
            if (s1[i] != 'z' && s2[i] != 'z')
                ans[i] = 'z';
            if (s1[i] != 'a' && s2[i] != 'a')
                ans[i] = 'a';
            if (s1[i] != 'b' && s2[i] != 'b')
                ans[i] = 'b';
            t1--;
            t2--;
        }
        else if (check(n - i - 1, t1, t2, sum)) {
            ans[i] = s1[i];
        }
        else {
            cout << -1;
            return 0;
        }
    }

    fr(i, n)
        cout << ans[i];
}