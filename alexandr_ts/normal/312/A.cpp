#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ll INF = 2e9;
const ld EPS = 1e-8;

string Fr = "lala.", Ra = "miao.";

bool Freda(string s) {
    int n = s.size();
    if (n < 5) return false;
    return s.substr(n - 5, 5) == Fr;
}

bool Rainbow(string s) {
    if (s.size() < 5) return false;
    return s.substr(0, 5) == Ra;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
     getline(cin, s);
    while (getline(cin, s)) {
        if (!(Freda(s) xor Rainbow(s)))
            cout << "OMG>.< I don't know!\n";
        else if (Freda(s))
            cout << "Freda's\n";
        else
            cout << "Rainbow's\n";
    }
}