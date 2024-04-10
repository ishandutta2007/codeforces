#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ll n;
    char c;
    cin >> n >> c;
    ll t = 0;
    if (n % 2 == 1) {
        if ((n - 1) % 4 == 0) {
            t = n / 2;
        } else {
            t = (n - 2) / 2;
        }
        t *= 6;    
        t += t / 6;
        t += ((n - 1) / 4) * 2;
    } else {
        n--;
        if ((n - 1) % 4 == 0) {
            t = n / 2;
        } else {
            t = (n - 2) / 2;
        }
        t++;
        t *= 6;
        t += t / 6;
        t += ((n - 1) / 4) * 2;
    }
    if (c == 'e') {
        t++; 
    }
    if (c == 'd') {
        t += 2; 
    }
    if (c == 'a') {
        t += 3;
    } 
    if (c == 'b') {
        t += 4;
    }
    if (c == 'c') {
        t += 5;
    }
    cout << t + 1 << endl;
}