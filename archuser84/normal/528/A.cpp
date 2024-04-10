///
///    "I, Giorno Giovanna, have a dream."
///
///                                    -Giorno Giovanna

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

struct X
{
    set<int> A;
    multiset<int, greater<int>> B;
    X(int n){A.insert(0); A.insert(n); B.insert(n);}
    void add(int i)
    {
        auto it = A.insert(i).F;
        auto b = it; b++;
        auto a = it; a--;
        auto tmp = B.lower_bound(*b - *a);
        B.erase(tmp);
        B.insert(*it - *a);
        B.insert(*b - *it);
    }
    int get(){return *B.begin();}
};

int main()
{
    FAST;
    int w, h, q;
    cin >> w >> h >> q;
    X W(w), H(h);
    while(q--)
    {
        char c; int i;
        cin >> c >> i;
        if(c == 'H') H.add(i);
        if(c == 'V') W.add(i);
        ll x = W.get(), y = H.get();
        cout << x*y << '\n';
    }
}