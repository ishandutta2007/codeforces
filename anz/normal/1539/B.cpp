#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, q;
string s;
ll psum[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        psum[i + 1] = psum[i] + s[i] - 'a' + 1;
    }

    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << psum[r] - psum[l - 1] << '\n';
    }
}