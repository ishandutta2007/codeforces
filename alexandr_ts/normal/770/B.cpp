#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const ll INF = 2e5 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N], b[N];

ll sumdig(ll n) {
    ll ans = 0;
    if (n < 10) return n;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

string numToStr(ll n) {
    string ans;
    while (n) {
        ans = (char)(n % 10 + '0') + ans;
        n /= 10;
    }
    return ans;
}

string solveTL(ll n) {
    ll ans = 1, ansnum = 1;
    frab(i, 2, n + 1)
        if (ans <= sumdig(i))
            ans = sumdig(i), ansnum = i;
    return numToStr(ansnum);
}

string solveOK(ll n1) {
    string s = numToStr(n1);
    int n = s.size();
    if (n == 1) {
        return s;
    }

    //bool not9 = false;
    int cnt8 = 0, cnt = 0;
    frab(i, 1, n)
        if (s[i] == '8')
            cnt8++;
        else if (s[i] < '8')
            cnt++;
    if (!cnt && cnt8 <= 1) {
        return s;
    }

    if (s[1] == '9') {
        frab(i, 2, n)
            if (s[i] != '9') {
                s[i - 1] = '8';
                frab(j, i, n)
                    s[j] = '9';
                return s;
            }
    }
    string answer;
    if (s[0] > '1')
        answer += (char)(s[0] - 1);
    frab(i, 1, n)
        answer += '9';
    return answer;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    cout << solveOK(n);
//    for (int i = 0; i < 1000; i++) {
//        ll n = rand() + 1;
//        if (solveOK(n) != solveTL(n)) {
//            cout << n << " " << solveOK(n) << " " << solveTL(n) << endl;
//        }
//    }
}