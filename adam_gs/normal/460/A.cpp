#include<bits/stdc++.h>
using namespace std;
#define rep(a,b) for(int a = 0; a < (b); ++a)
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, m, d=0;
        cin >> n >> m;
        while(n>0) {
                ++d;
                --n;
                if(d%m==0) ++n;
        }
        cout << d;
}