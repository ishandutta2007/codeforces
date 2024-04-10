#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef long double ld;

string s;


int main(){
    long long n, i, x, y;
    cin >> n;
    x = 1;
    y = 1;
    forn(i, n){
        cin >> s;
        if (s == "UL" || s == "DR")
            x++;
        if (s == "UR" || s == "DL")
            y++;
        if (s == "ULDR"){
            x++;
            y++;
        }
    }
    cout << x * y;

    return 0;

}