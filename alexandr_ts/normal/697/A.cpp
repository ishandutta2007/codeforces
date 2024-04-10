#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e3;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    ll t, s, x;
    cin >> t >> s >> x;
    if (x < t)
        cout << "NO";
    else if ((x - t) % s == 0)
        cout << "YES";
    else if ((x - t - 1) % s == 0 && x - t - 1)
        cout << "YES";
    else
        cout << "NO";

}