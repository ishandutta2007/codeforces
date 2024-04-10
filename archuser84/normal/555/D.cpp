///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 200'010;
const int inf = 1 << 30;
int n;
pii x[N];
int mm[N];

int find_right(int i, int l){
    return upper_bound(x,x+n,make_pair(x[i].first+l, inf))-1 -x;
}

int find_left(int i, int l){
    return lower_bound(x,x+n,make_pair(x[i].first-l, -inf)) -x;
}

inline int dis(int a, int b){
    return abs(x[b].first - x[a].first);
}

void update(int& a, int& l, int b){
    l -= dis(a, b);
    a = b;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(false);
    int q;
    cin >> n >> q;
    Loop(i,0,n)
        cin >> x[i].first, x[i].second = i;
    sort(x,x+n);
    Loop(i,0,n)
        mm[x[i].second] = i;
    while(q--)
    {
        int a, l;
        cin >> a >> l; a = mm[a-1];
        update(a, l, find_right(a, l));

        while(true)
        {
            int b = find_left(a, l);
            if(a == b)
                break;
            int d = dis(a, b);
            int k = l/d; l %= d;
            if(k&1)
            {
                a = b;
                update(a, l, find_right(a, l));
            }
        }
        cout << x[a].second+1 << '\n';
    }
}