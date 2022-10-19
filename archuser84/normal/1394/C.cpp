#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct my_shape
{
    int y;
    int l, r;
    void merge(my_shape S)
    {
        if((*this).y < S.y)
            swap(*this, S);
        l = max(l, S.l - (y - S.y));
        r = min(r, S.r + (y - S.y));
        if(l > r)
        {
            int newl = (l+r)/2;
            int newr = (l+r+1)/2;
            int newy = y + (l-r+1)/2;
            l = newl; r = newr; y = newy;
        }
    }
};

const int N = 500'010;
pair<int, int> S[N] = {};
string stmp;
int n;
pii ans;

my_shape make(pii S, int X)
{
    return {abs(S.F - X),
            min(S.S, S.S - (S.F - X)),
            max(S.S, S.S - (S.F - X))};
}

int findMax(int X)
{
    my_shape T = make(S[0], X);
    Loop(i, 1, n)
        T.merge(make(S[i], X));
    ans.F = X; ans.S = max(T.l, 0);
    if(X == 0 && ans.S == 0) ans.S++;
    return max(T.y, T.y + ans.S - T.r);
}

int ter()
{
    int l=0, r=N;
    while(l < r)
    {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        int a = findMax(m1);
        int b = findMax(m2);
        if(a <= b)
            r = m2-1;
        else
            l = m1+1;
    }
    return findMax(l);
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
    {
        cin >> stmp;
        for(auto c : stmp)
            c == 'B'? S[i].first++: S[i].second++;
    }
    cout << ter() << '\n';
    Loop(i,0,ans.F)
        cout << 'B';
    Loop(i,0,ans.S)
        cout << 'N';
}