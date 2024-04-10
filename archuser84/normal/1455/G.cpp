///
///    "Yare Yare Daze"
///
///                                    -Jotaro Kujo

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize ("O0")

const int N = 200'010;

struct ins
{
    int8_t t;
    int a, b;
}op[N];
int n, s;

void debug(auto& x, ll ttl)
{
    for(auto& y : x)
        cout << y.F << ": " << y.S+ttl << '\n';
    cout << '\n';
}

int ccnt = 0;

tuple<map<int, ll>*, multiset<ll>*, ll> solve(int bi, int bv)
{
    map<int, ll>* ans = new map<int, ll>; (*ans)[bv] = 0;
    multiset<ll>* vs  = new multiset<ll>; vs->insert(0);
    ll ttl = 0;
    Loop(i, bi, n)
    {
        //cout << bi << ' ' << i << '\n';
        //debug(ans, ttl);
        //cout << ++ccnt << '\n';
        if(op[i].t == 0)
        {
            ll tmp = *vs->begin() + ttl;
            ttl += op[i].b;
            if(op[i].a != s) {
                if(ans->count(op[i].a)) vs->erase(vs->find((*ans)[op[i].a]));
                (*ans)[op[i].a] = tmp - ttl;
                vs->insert((*ans)[op[i].a]);
            }
        }
        else if(op[i].t == 1)
        {
            if(ans->count(op[i].a)){
                auto [ans2, vs2, ttl2] = solve(i+1, op[i].a);
                ll v = (*ans)[op[i].a] + ttl + ttl2;
                vs->erase(vs->find((*ans)[op[i].a]));
                ans->erase(op[i].a);
                if(ans->size() < ans2->size())
                {
                    swap(ans, ans2);
                    swap(vs, vs2);
                    swap(ttl, v);
                }
                for(auto p : *ans2)
                {
                    //cout << ++ccnt << '\n';
                    if(!ans->count(p.F) || (*ans)[p.F] + ttl > p.S + v)
                    {
                        if(ans->count(p.F)) vs->erase(vs->find((*ans)[p.F]));
                        (*ans)[p.F] = p.S + v - ttl;
                        vs->insert((*ans)[p.F]);
                    }
                }
            }
            i = op[i].b;
        }
        else if(op[i].t == 2) break;
    }
    //cout << bi << ' ' << n << '\n';
    //debug(ans, ttl);
    return {ans, vs, ttl};
}

int main()
{
    FAST;
    cin >> n >> s;
    stack<int> ifs;
    Loop(i,0,n)
    {
        string a;
        cin >> a;
        if(a[0] == 's'){
            op[i].t = 0;
            cin >> op[i].a >> op[i].b;
        }
        if(a[0] == 'i'){
            op[i].t = 1;
            ifs.push(i);
            cin >> op[i].a;
        }
        if(a[0] == 'e'){
            op[i].t = 2;
            op[i].a = ifs.top(); ifs.pop();
            op[op[i].a].b = i;
        }
    }
    auto [a, b, c] = solve(0, 0);
    cout << c + *(*b).begin() << '\n';
}