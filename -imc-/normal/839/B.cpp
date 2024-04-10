#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

using li = long long;

bool can(int h1, int h2, int h3, int h4, int n1, int n2, int n4, int offsum) {
    int c1 = min(h1, n1);
    h1 -= c1;
    n1 -= c1;
    
    int c11 = min(h3, n1);
    h3 -= c11;
    n1 -= c11;
    h2 += c11;
    
    n2 += n1 / 2;
    h2 += h1;
    h2 += h3 * 2;
    
    //printf("have %d\n", h2);
    
    int c2 = min(h2, n2);
    h2 -= c2;
    n2 -= c2;
    
    n4 += n2 / 2;
    h4 += h2;
    
    offsum += h2;
    
    //printf("%d %d\n", n4, offsum);
    return n4 >= offsum;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    int h4 = 0, h3 = 0, h2 = 0, h1 = 0;
    int offsum = 0;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        
        //printf("A %d\n", a);
        
        if (a % 4 == 0) h4++;
        else if (a % 2 == 0) h2++;
        else if (a % 4 == 1) h1++;
        else h3++;
        
        offsum += a / 4;
    }
    
    //printf("haves %d %d %d %d\n", h1, h2, h3, h4);
    
    for (int n1 = 0; n1 <= n; n1++) {
        int n2 = 2 * n + n1;
        int n4 = n - n1;
        
        if (can(h1, h2, h3, h4, n1, n2, n4, offsum)) {
            //printf("can with %d %d %d\n", n1, n2, n4);
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    solve();
    
    return 0;
}