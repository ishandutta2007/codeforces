#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int cntUSD = 7;
const int USD[cntUSD] = {1, 2, 5, 10, 20, 50, 100};
const int limitUSD[cntUSD] = {2, 5, 2, 2, 5, 2, 100};

const int cntEUR = 6;
const int EUR[cntEUR] = {5, 10, 20, 50, 100, 200};
const int limitEUR[cntEUR] = {2, 2, 5, 2, 2, 1000000};

ll n, d, e;
ll answer;

void backEUR(int step) {
    if (step + 1 == cntEUR) {
        answer = min(answer, n % (EUR[step] * e));
    } else {
        for (int cnt = 0; cnt < limitEUR[step]; cnt++) {
            ll aux = cnt * EUR[step] * e;
            if (aux > n) continue;
            n -= aux;
            backEUR(step + 1);
            n += aux;
        }
    }
}

void backUSD(int step) {
    for (int cnt = 0; cnt < limitUSD[step]; cnt++) {
        ll aux = cnt * USD[step] * d;
        if (aux > n) continue;

        n -= aux;
        if (step + 1 == cntUSD)
            backEUR(0);
        else
            backUSD(step + 1);
        n += aux;
    }
}


int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> d >> e;
    answer = n;

    backUSD(0);
    cout << answer;


    return 0;
}