#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
                string x, a="";
                cin >> x;
                a+=x[0];
                for(int i = 1; i < x.size(); i+=2) a+=x[i];
                cout << a << '\n';
        }
}