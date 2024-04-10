#include <bits/stdc++.h>
#define fr first
#define sc second
#define MP make_pair
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jigglypuff
#define ld long double
#define itn int
using namespace std;
lli gcd(lli a, lli b) {return (b==0LL ? a : gcd(b, a % b));}
ld dist(ld x1, ld y1, ld x2, ld y2)
{

    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
char vow[] = {'a', 'e', 'i', 'o', 'u'};
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

const int N = 222;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);

lli bp(lli a, lli b = mod - 2)
{

    lli ret = 1;
    while(b)
    {

        if(b & 1) ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}

int n;
int pat;
string s;
int main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    cin >> n >> s;
    for(int x = 'z'; x >= 'a'; x--)
    {
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < s.length(); i++)
            {
                if(s[i] == x)
                {
                    if(s[max(0, i - 1)] == x - 1 || s[min(n - 1, i + 1)] == x - 1)
                    {
                        s.erase(i, 1);
                        pat++;
                    }
                }
            }
        }
    }
    cout << pat <<endl;
    return 0;
}