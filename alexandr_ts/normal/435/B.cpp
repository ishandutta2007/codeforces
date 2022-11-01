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

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    fr(i, n) {
        int pos = i, mx = -INF;
        frab(j, i, min(i + k + 1, n))
            if (s[j] > mx) mx = s[j], pos = j;
        for (int j = pos; j > i && k; j--)
            swap(s[j], s[j - 1]), k--;
        //1cout << s << endl;
    }
    cout << s;
}