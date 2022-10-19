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

const int N = 5e5 + 30;
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
int qan1, qan2;
int a[N], b[N];
int main()
{
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1 && b[i] == 0) qan1++;
        else if(a[i] == 0 && b[i] == 1) qan2++;
    }
    if(qan1 == 0) cout << -1;
    else
    {
        int sm = (qan2 + qan1 - 1) / qan1;
        if(sm * qan1 <= qan2) sm++;
        cout << sm << endl;
    }
    return 0;
}