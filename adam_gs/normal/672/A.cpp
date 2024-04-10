#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int main() {
    int n;
    cin >> n;
    string x="";
    for (int i = 1; len(x)<n; ++i) {
        string p="";
        int pom=i;
        while (pom>0) {
            char x=pom%10+'0';
            p+=x;
            pom/=10;
        }
        for (int i = len(p)-1; i>=0; --i) {
            x+=p[i];
        }
    }
    cout << x[n-1];
}