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

const int N = 200'010;
unordered_map<int, int> cnt;
int n;

std::ostream& operator<<(std::ostream& ost, __int128 x)
{
    if(x == -x && x != 0)
    {
        ost << "-170141183460469231731687303715884105728";
        return ost;
    }
    if(x < 0)
    {
        ost << '-';
        x = -x;
    }
    char s[64];
    int size;
    for(size = 0; x; ++size)
    {
        s[size] = x%10 + '0';
        x /= 10;
    }
    for(int i = size-1; i >= 0; --i)
        ost << s[i];
    if(!size)
        ost << '0';
    return ost;
}

std::istream& operator>>(std::istream& ist, __int128& x)
{
    char s[64];
    ist >> s;
    int i = s[0] == '-';
    bool sign = i;
    x = 0;
    for(; s[i]; ++i)
    {
        x *= 10;
        x += s[i] - '0';
    }
    if(sign)
        x = -x;
    return ist;
}

int main()
{
    FAST;
    cin >> n;
    __int128 ans = 0;
    __int128 sum = 0;
    Loop(i,0,n)
    {
        __int128 x;
        cin >> x;
        ans += i*x - sum;
        sum += x;
        ans -= cnt[x-1];
        ans += cnt[x+1];
        cnt[x]++;
    }
    cout << ans << '\n';
}