#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e12 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

int main() {
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    //vector <int> a(n);
    //vector <int> ans(n, 9);
    string a;
    cin >> a;
    string ans;
    fr(i, n)
        ans += (char)9;
    fr(i, n)
        a[i] -= '0';
    //fr(i, n)
        //cin >> a[i];
    fr(i, n) {
        rotate(a.begin(), a.begin() + 1, a.end());
        int x = (10 - a[0]) % 10;
        fr(j, n)
            a[j] = (a[j] + x) % 10;
        if (a < ans)
            ans = a;
    }
    fr(i, n)
        cout << (char)(ans[i] + '0');
}