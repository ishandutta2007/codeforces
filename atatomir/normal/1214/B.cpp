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

int b, g, n;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> b >> g >> n;
    int maxi = min(n, b);
    int mini = max(0, n - g);

    cout << maxi - mini + 1;


    return 0;
}