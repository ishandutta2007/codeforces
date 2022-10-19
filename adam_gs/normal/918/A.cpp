#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int fib[1000];

int main() {
    int n1=1, n2=1;
    while (n1<=1000 && n2<=1000) {
        fib[n2-1]=1;
        int pom=n2;
        n2=n1+n2;
        n1=pom;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        if (fib[i]==0) {
            cout << 'o';
        } else {
            cout << 'O';
        }
    }
}