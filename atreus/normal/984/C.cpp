#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxn = 1111;
const int MAXN = 1e5 + 100;
const int inf = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        ll tmp = __gcd (a, b);
        a /= tmp;
        b /= tmp;
        while (true){
            c = __gcd (b, c);
            if (c == 1)
                break;
            b /= c;
        }
        if (b == 1)
            cout << "Finite \n";
        else
            cout << "Infinite \n";
    }
}