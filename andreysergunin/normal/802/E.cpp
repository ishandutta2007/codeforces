#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 250;

bool eq(ld a, ld b)
{
    if (a > b) {
        swap(a, b);
    }
    if (b / a < 2) {
        return true;
    }
    return false;
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        ll sum = 0, sum2 = 0;
        ll maxx = 0;
        for (int i = 0; i < nmax; ++i) {
            ll x;
            cin >> x;
            maxx = max(maxx, x);
            sum += x;
            sum2 += x * x;
        }
        ld mean = ld(sum) / nmax;
        ld disp = ld(sum2) / nmax - (ld(sum) / nmax) * (ld(sum) / nmax);
        std::cout << fixed;
        cout.precision(0);
        if (eq(mean, disp)) {
            cout << mean << "\n";
        } else {
            ld ans = maxx * ld(nmax + 1) / ld(nmax) / 2;
            cout << ans << "\n";
        }
    }

}