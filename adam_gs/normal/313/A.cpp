#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        string x;
        cin >> x;
        if(x.size()==3 && x[0]=='-' && x[2]=='0') cout << 0;
        else if(x[0]=='-') {
                rep(i, x.size()-2) cout << x[i];
                cout << min(x[x.size()-1], x[x.size()-2]);
        } else cout << x;
}