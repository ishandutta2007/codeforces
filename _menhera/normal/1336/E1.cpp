#include<bits/stdc++.h>
using namespace std;

const int MAXM = 35;
const int MAXN = 202020;
const int MOD = 998244353;

uint64_t ans[MAXM+1];
vector<uint64_t> RREF;

uint64_t msb(uint64_t x)
{
    int lg = 63-__builtin_clzll((unsigned long long)x);
    return ((uint64_t)1) << lg;
}

void put(uint64_t x)
{
    for(auto y: RREF)
    {
        uint64_t m = msb(y);
        if(x&m) x ^= y;
    }

    if(x)
    {
        uint64_t m = msb(x);
        for(auto&y: RREF)
            if(y&m)
                y ^= x;
        RREF.push_back(x);
    }
}

int N, M;
int main()
{
    cin >> N >> M;
    vector<uint64_t> VV;
    for(int i=0; i<N; ++i)
    {
        uint64_t T; cin >> T;
        VV.push_back(T);
    }
    sort(VV.begin(), VV.end());
    for(auto x: VV) put(x);

    for(int i=0; i<(int)RREF.size(); ++i)
    {
        for(int j=0; j<i; ++j)
        {
            assert(!(RREF[j]&msb(RREF[i])));
            assert(!(RREF[i]&msb(RREF[j])));
        }
    }
    for(auto&x: RREF)
        x ^= msb(x);
    
    assert((int)RREF.size() <= M);

    using pui = pair<uint64_t, int>;

    vector<pair<pui, long long> > V;
    V.emplace_back(make_pair(uint64_t(0), 0), 1LL);
    for(auto x: RREF)
    {
        vector<pair<pui, int> > U;
        for(auto[pp, ii]: V)
        {
            auto [vv, cc] = pp;
            U.emplace_back(pp,ii);
            U.emplace_back(make_pair(vv^x, cc+1), ii);
            //cout << vv << " " << cc << " " << ii << endl;
        }
        //cout<<endl;
        sort(U.begin(), U.end());
        V.clear();
        auto [cur, cnt] = U[0];
        for(int i=1; i<(int)U.size(); ++i)
        {
            auto[pp, ii] = U[i];
            if(cur == pp)
            {
                cnt += ii;
                if(cnt >= MOD) cnt -= MOD;
            }
            else
            {
                V.emplace_back(cur, cnt);
                cur = pp; cnt = ii;
            }
        }
        V.emplace_back(cur, cnt);
    }
    for(auto [pp, ii]: V)
    {
        auto [vv, cc] = pp;
        int tot = __builtin_popcountll((unsigned long long)vv)+cc;
        ans[tot] += ii;
        if(ans[tot] >= MOD) ans[tot] -= MOD;
    }
    long long p = 1;
    for(int i=0; i<N-(int)RREF.size(); ++i) p = (p+p)%MOD;
    for(int i=0; i<=M; ++i)
    {
        ans[i] = ans[i]*p%MOD;
        cout << ans[i] << " ";
    }
    cout<<endl;
}