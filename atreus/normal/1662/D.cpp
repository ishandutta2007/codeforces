#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 77;


string get(string s) {
    string r;
    int ca = 0 , cc = 0 , cb = 0;
    for(char c : s) {
        if(c == 'B') cb ^= 1;
        if(c == 'A') {
            if(cc == 1) r += "1";
            cc = 0;
            ca ^= 1;
        }
        if(c == 'C') {
            if(ca == 1) r += "0";
            ca = 0;
            cc ^= 1;
        }
        while((int) r.size() >= 2) {
            int sz = r.size();
            if(r[sz - 2] == r[sz - 1]) r.pop_back() , r.pop_back();
            else break ;
        }
    }
    assert(ca + cc <= 1);
    if(cc == 1) r += "1";
    if(ca == 1) r += "0";
    while((int) r.size() >= 2) {
        int sz = r.size();
        if(r[sz - 2] == r[sz - 1]) r.pop_back() , r.pop_back();
        else break ;
    }
    if(cb == 0) r += "0";
    else r += "1";
    return r;
}
string s , t;
void test() {
    cin >> s;
    cin >> t;
    //cout << get(s) << ' ' << get(t) << endl;
    if(get(s) == get(t)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int tst = 1;
    cin >> tst;
    while(tst --)
        test();
    return 0;
}