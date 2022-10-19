#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

vector<int> divs;
vector<int> facs;

bool isPrime(int x)
{
    if(x < 2)
        return 0;
    for(int i = 2; i*i <= x; ++i)
    {
        if(x%i == 0)
            return 0;
    }
    return 1;
}

void factor(int x)
{
    for(int i = 2; i*i <= x; ++i)
    {
        if(x%i == 0)
        {
            facs.push_back(i);
            while(x%i == 0)
                x /= i;
        }
    }
    if(x > 1)
        facs.push_back(x);
}

void findDivs(int x)
{
    for(int i = 2; i*i <= x; ++i)
    {
        if(x%i == 0)
        {
            divs.push_back(i);
            if(i*i != x)
                divs.push_back(x/i);
        }
    }
    divs.push_back(x);
}

bool isOne(int x)
{
    for(int i = 2; i*i <= x; ++i)
    {
        if(x%i)
            continue;
        return i*i != x && isPrime(x/i);
    }
}

void solve()
{
    divs.clear();
    facs.clear();
    int x;
    cin >> x;
    factor(x);
    findDivs(x);
    sort(all(divs));
    int y = facs.front() * facs.back();
    for(int f : facs)
    {
        Loop(i,0,divs.size())
        {
            if(divs[i] % f || divs[i] == y)
                continue;
            cout << divs[i] << ' ';
            divs[i] = 1;
        }
    }
    cout << y << '\n' << isOne(x) << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}