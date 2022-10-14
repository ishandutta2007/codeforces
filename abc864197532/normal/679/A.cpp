#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    set <int> prime;
    fop (i,2,50) {
        bool is = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) is = false;
        }
        if (is) prime.insert(i);
    }
    int now = -1;
    string s;
    for (int i : prime) {
        cout << i << endl;
        cin >> s;
        fflush(stdout);
        if (s[0] == 'y') {
            if (now == -1) now = i;
            else {
                cout << "composite" << endl;
                return 0;
            }
        }
    }
    if (now == -1 or now * now > 100) {
        cout << "prime" << endl;
        return 0;
    }
    cout << now * now << endl;
    cin >> s;
    fflush(stdout);
    if (s[0] == 'y') {
        cout << "composite" << endl;
    } else {
        cout << "prime" << endl;
    }
}