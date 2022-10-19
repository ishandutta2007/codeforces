#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int a = 0; a < (b); ++a)

int main() {
    int n;
    cin >> n;
    rep(i, n) {
        int p = i+1;
        if (n%p==0) {
            bool t = true;
            while(p>0) {
                if(p%10!=4 && p%10!=7) t=false;
                p/=10;
            }
            if (t==true) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}