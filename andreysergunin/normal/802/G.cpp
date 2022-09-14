#include <bits/stdc++.h>
#include <thread>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    string t = "heidi";
    int i = 0;
    int ptr = 0;

    while (ptr < sz(t) && i < sz(s)) {
        if (s[i] == t[ptr]) {
            ++i, ++ptr;
        } else {
            ++i;
        }
    }

    cout << (sz(t) == ptr ? "YES\n" : "NO\n");

}