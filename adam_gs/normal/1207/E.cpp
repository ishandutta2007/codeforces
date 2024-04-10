#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
    cout << "? ";
    rep(i, 100) {
        cout << (i+1)*128 << " ";
    }
    cout << endl;
    int x1;
    cin >> x1;
    cout << "? ";
    rep(i, 100) {
        cout << i+1 << " ";
    }
    cout << endl;
    int x2;
    cin >> x2;
    x2/=128; x2*=128;
    x1%=128;
    cout << "! " << x2+x1 << endl;
}