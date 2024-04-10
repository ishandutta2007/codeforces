

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>


using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
    if (b == 0) return a;
    a %= b;
    return gcd(b, a);
}
int absl(int a) { if (a < 0) return -a; return a; }
int v[1000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int ii = 0; ii < tests; ii++) {
        int n, m;
        cin >> n >> m;
        
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long z = 0;
        for (int j = 0; j < m; j++) {
            long long x;
            cin >> x;
            z = gcd(x, z);
        }
        long long tot = 0;
        long long tot2 = 0;
        for (int i = 0; i < z; i++) {
            long long s = 0;
            int mn = absl(v[i]);
            int ng = 0;
            for (int j = i; j < n; j += z) {
                s += absl(v[j]);
                if (absl(v[j]) < mn) mn = absl(v[j]);
                if (v[j] <= 0) ng++;
            }
            tot += s;
            tot2 += s;
            if (ng % 2 == 1) tot -= 2 * mn;
            if (ng % 2 == 0) tot2 -= 2 * mn;
            
        }
        

        cout << max(tot, tot2) << endl;

    }

}