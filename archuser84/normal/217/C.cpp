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
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 1'000'010;
char s[N];
int n;

struct expr
{
    int x=0;
    int d=0;
    char op;
};

vector<expr> S;

void add_expr(int x, int d, char op)
{
    while(S.size() && S.back().d == d)
    {
        int y = S.back().x;
        char op2 = S.back().op;
        S.pop_back();
        int ans = 0;
        switch(op2)
        {
            case '&':
                if(((x&4) && (y&4)) || ((x&2) && (y&4)) || ((x&4) && (y&2))) ans ^= 4;
                if((x&2) && (y&2)) ans ^= 2;
                if((x&1) || (y&1) || ((x&4) && (y&4))) ans ^= 1;
                break;
            case '|':
                if(((x&4) && (y&4)) || ((x&1) && (y&4)) || ((x&4) && (y&1))) ans ^= 4;
                if((x&1) && (y&1)) ans ^= 1;
                if((x&2) || (y&2) || ((x&4) && (y&4))) ans ^= 2;
                break;
            case '^':
                if(((x&4) && (y&2)) || ((x&4) && (y&1)) || ((x&2) && (y&4)) || ((x&1) && (y&4))) ans ^= 4;
                if(((x&2) && (y&1)) || ((x&1) && (y&2)) || ((x&4) && (y&4))) ans ^= 2;
                if(((x&2) && (y&2)) || ((x&1) && (y&1)) || ((x&4) && (y&4))) ans ^= 1;
                break;
        }
        x = ans;
        d--;
    }
    S.push_back({x,d,op});
}

int solve()
{
    int d = 0;
    int ld, x;
    Loop(i,0,n+1)
    {
        if(s[i] == '(') d++;
        if(s[i] == ')') d--;
        if(s[i] == '?' || s[i] == '0' || s[i] == '1')
        {
            switch(s[i]) {
                case '0': x = 0b001; break;
                case '1': x = 0b010; break;
                case '?': x = 0b100; break;
            }
            ld = d;
        }
        if(s[i] == '&' || s[i] == '|' || s[i] == '^' || s[i] == '\0')
        {
            add_expr(x, ld, s[i]);
        }
    }
    if(S.size() != 1 || S[0].d != 0 || S[0].op != 0) cout << "ERROR\n";
    return S[0].x;
}

int main()
{
    FAST;
    int dummy;
    cin >> dummy;
    cin >> s; n = strlen(s);
    cout << YN(solve() & 0b100);
}