#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        // int x = 6;
        int b = 0;
        int pw = 1;
        for(int i = 0; i < 29; i ++) {
            b += pw;
            int a = b + pw * 2;
            cout << "? " << a << " " << b << endl;
            // int ans = __gcd(x+a,x+b);
            // cout << ans << endl;
            int ans;
            cin >> ans;
            if(ans != pw * 2) {
                b -= pw;
            }
            pw *= 2;
        }
        if(b == 0) {
            cout << "! 536870912" << endl;
            continue;
        }
        int a = b+1073741824;
        cout << "? " << a << " " << b << endl;
        // int ans = __gcd(x+a,x+b);
        int ans;
        cin >> ans;
        if(ans != 1073741824) {
            b += pw;
        }
        pw *= 2;
        cout << "! " << (pw - b) << endl;
    }
    return 0;
}

/*

1
2
4
8
16
32
64
128
256
512
1024
2048
4096
8192
16384
32768
65536
131072
262144
524288
1048576
2097152
4194304
8388608
16777216
33554432
67108864
134217728
268435456
536870912
1073741824
*/