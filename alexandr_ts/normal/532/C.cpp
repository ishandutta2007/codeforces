#include <bits/stdc++.h>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> prl;
typedef pair <int, int> pr;
typedef string str;

const int N = 2 * 1e5;
const ll INF = 1e15;
const ld EPS = 1e-6;


int main() {
    //freopen("a.in", "r", stdin);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 + y1 <= max(x2, y2) || x1 <= x2 && y1 <= y2)
            cout << "Polycarp";
        else
            cout << "Vasiliy" ;

}