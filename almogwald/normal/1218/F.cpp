/**/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>

typedef long long int63;
using namespace std;
#define forl(name,start,end,jump) for(int63 name = start; name < end; name+=jump)
#define forlb(name,start,end,jump) for(int63 name = start - 1; name >= end; name+=jump)
#define forn(name,start,end) forl(name,start,end,1)
#define fornb(name,start,end) forlb(name,start,end,-1)
#define fort(start,end) forn(i,start,end)
#define fortb(start,end) fornb(i,start,end)
#define forto(start,end) forn(j,start,end)
#define fortoo(start,end) forn(l,start,end)
#define all(vec) vec.begin(),vec.end()
#define makeitem(itemname,itemtype) itemtype itemname; cin >> itemname
#define makeint(intname) int63 intname; cin >> intname
#define makeN int63 n; cin >> n
#define makeM int63 m; cin >> m
#define makeL int63 l; cin >> l
#define makeT int63 t; cin >> t
#define makeK int63 k; cin >> k
#define point pair<int63,int63>
#define in(name) cin >> name;
#define tosort(name) name.begin(),name.end()
int63 powmod(int63 base, int63 exponent, int63 mod) {
    int63 result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 0) {
            exponent /= 2;
            base = (base * base) % mod;
        } else {
            result = (result * base) % mod;
            exponent /= 2;
            base = (base * base) % mod;
        }
    }
    return result;
}
bool decresing(int63 x, int63 y) {
    return x > y;
}

int63 trin(int63 start, int63 stop) {
    return (stop - start + 1) * (stop + start) / 2;
}

bool sortvectorf(point a, point b) {
return((a.first > b.first) || (a.first == b.first && a.second > b.second));
}

bool sortvectorfv(point a, point b) {
    return((a.first > b.first) || (a.first == b.first && a.second < b.second));
}

bool sortvectors(point a, point b) {
return((a.second > b.second) || (a.second == b.second && a.first > b.first));
}

bool negasortvectorf(point a, point b) {
return((a.first < b.first) || (a.first == b.first && a.second < b.second));
}

bool negasortvectors(point a, point b) {
return((a.second < b.second) || (a.second == b.second && a.first < b.first));
}

vector<vector<int63>> findPermutations(vector<int63> &a)
{

    // Sort the given array
    sort(a.begin(), a.end());
    vector<vector<int63> > sol;
    // Find all possible permutations
    do {
        sol.push_back(a);
    } while (next_permutation(a.begin(),a.end()));
    return sol;
}

int63 gcd(int63 a, int63 b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return gcd(b % a, a);
}

bool isprime(int63 n) {
    fort(2, n) {
        if (i * i > n) {
            break;
        }
        if ((n / i) * i == n) {
            return false;
        }
    }
    return true;
}

int63 fdivisor(int63 n,int63 fro) {
    fort(1, n + 1) {
        if ((n / i) * i == n && i >= fro) {
            return i;
        }
    }
    return -1;
}

vector<int63> divlist(int63 n) {
    vector<int63> curr;
    fort(2, n) {
        if ((int63)i * i > n) {
            break;
        }
        if ((n / i) * i == n) {
            curr.push_back(i);
            curr.push_back(n / i);
        }
        if ((int63)i * i == n) {
            curr.pop_back();
        }
    }

    sort(all(curr));
    return curr;
}
int63 countdivisors(int63 n,int63 divd,int63 rem) {
    vector<int63> divs = divlist(n);
    int63 tot = 0;
    fort(0, divs.size()) {
        if (divs[i] % divd == rem) {
            tot++;
        }
    }
    if (n % divd == rem) {
        tot++;
    }
    return tot;
}
int63 digsum(int63 num) {
    int63 cr = 0;
    while (num > 0) {
        cr += num % 10;
        num /= 10;
    }
    return cr;
}

int63 modInverse(int63 a, int63 b) {
    int63 m = b;
    int63 y = 0, x = 1;
    while (a > 1) {
        int63 q = a / m;
        int63 t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += b;
    }
    return x;
}
int63 azeret(int63 num, int63 mod) {
    int63 sil = 1;
    while (num > 1) {
        sil *= num;
        sil %= mod;
        num--;
    }
    return sil;
}
int63 moddiv(int63 to, int63 by, int63 mod) {
    to %= mod;
    while (to % by != 0) {
        to += mod;
        if (to > (by + 1) * mod) {
            return -1;
        }
    }
    return (to / by) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //code here:
    makeN;
    makeM;
    vector<int63> lift(n), price(n);
    fort(0, n) {
        cin >> lift[i];
    }
    int63 a;
    cin >> a;
    fort(0, n) {
        cin >> price[i];
    }
    vector<int63> needs(n),boost(n);
    fort(0, n) {
        if (lift[i] > m + a * (i + 1)) {
            cout << -1 << endl;
            return 0;
        }
        needs[i] = (lift[i] - m + a - 1) / a;
        if (i > 0 && needs[i] < needs[i - 1]) {
            needs[i] = needs[i - 1];
        }
        if (i == 0 && needs[i] < 0) {
            needs[i] = 0;
        }
        if (i > 0) {
            boost[i] = needs[i] - needs[i - 1];
        } else {
            boost[i] = needs[i] - 0;
        }
    }
    if (needs[n-1] == 0) {
        cout << 0 << endl;
        return 0;
    }
    int63 cost = 0;
    multiset<int63>prices;
    fort(0, n) {
        prices.insert(price[i]);
        while (boost[i] > 0) {
            cost += *prices.begin();
            prices.erase(prices.begin());
            boost[i]--;
        }
    }
    cout << cost << endl;
    return 0;
}
/**/