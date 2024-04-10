#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e3 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

string t = "iouea";

int f(string s) {
    int cnt = 0;
    fr(i, s.size())
        if (s[i] == 'i' || s[i] == 'a' || s[i] == 'o' || s[i] == 'u' || s[i] == 'e')
            cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    //cout << f(s1) << endl;
    if (f(s1) == 5 && f(s2) == 7 && f(s3) == 5)
        cout << "YES";
    else
        cout << "NO";
}