/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

void goHome(){
    cout << "No solution";
    exit(0);
}

int main() {

    int a, b, n;
    cin >> a >> b >> n;

    if(a == 0 && b == 0){
        cout << 3;
        exit(0);
    }

    if(a == 0)
        goHome();

    if(b == 0){
        cout << 0;
        exit(0);
    }

    if(abs(b) % abs(a))
        goHome();

    b /= a;

    bool bol = false;

    if(b < 0){
        if(n % 2 == 0)
            goHome();
        bol = true;
        b = -b;
    }



    int d = pow(b, 1.0 / (double) n + 0.0000001);

    int g = pow(d, n) - b;

    if(g != 0)
        goHome();


    if(bol)
        cout << "-";

    cout << d;


}