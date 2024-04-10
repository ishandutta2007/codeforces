#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    while(t--) {
        int n, l;
        cin >> n >> l;
        vector<int> as(n);
        for(int &a : as) {
            cin >> a;
        }
        ld ls = 1;
        ld rs = 1;
        ld lpos = 0;
        ld rpos = l;
        int li = 0;
        int ri = n - 1;
        ld timer = 0;
        while(true) {
            long double interT = (rpos-lpos)/(ls+rs);
            long double LE = (as[li]-lpos)/ls;
            long double RE = (rpos-as[ri])/rs;
            // cout << " " << LE << " " << RE << " " << interT << " " << rpos << " " << li << " " << ri << "\n";
            if((interT < LE && interT < RE) || li > ri) {
                // int;
                timer += interT;
                cout << timer << "\n";
                break;
            } else if(LE < RE) {
                // le
                // cout << "  le\n";
                timer += LE;
                lpos = as[li];
                rpos -= rs * LE;
                li ++;
                ls ++;
            } else {
                // re
                // cout << "  re\n";
                timer += RE;
                rpos = as[ri];
                lpos += ls * RE;
                ri --;
                rs ++;
            }
        }
    }
    return 0;
}

/*
1
5 7
1 2 3 4 6
*/