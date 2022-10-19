#include <bits/stdc++.h>


using namespace std;

#define long long long

vector<char> ch;
vector<long> cnt;

long gcd(long x, long y) {
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    if (x < y) {
        ch.push_back('B');
        cnt.push_back(y / x);
        return gcd(x, y % x);
    } else {
        ch.push_back('A');
        cnt.push_back(x / y);
        return gcd(x % y, y);
    }
}
        
int main() {
    long x, y;
    cin >> x >> y;
    if (x == y || gcd(x, y) != 1) {
        cout << "Impossible\n";
    } else {
        //reverse(ch.begin(), ch.end());
        //reverse(cnt.begin(), cnt.end());
        --cnt.back();
        for (int i = 0; i < ch.size(); ++i) {
            cout << cnt[i] << ch[i];
        }
        cout << endl;
    }
    return 0;
}