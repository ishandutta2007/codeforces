#include <bits/stdc++.h>
using namespace std;

const int MAXQ = 2e5;

vector<int> solve(int K, vector<tuple<uint32_t, uint32_t, int> > V)
{

    uint32_t mask = (((uint32_t)1) << K)-1;
    
    vector<int> HT(1<<K), LT(1<<K);
    for(auto [l, r, v]: V) if(v)
    {
        uint32_t lhi = l >> K, llo = l & mask;
        uint32_t rhi = r >> K, rlo = r & mask;
        if(lhi == rhi){ LT[llo]++; if(rlo != ((1<<K)-1)) LT[rlo+1]--; }
        else
        {
            LT[llo]++; LT[0]++; if(rlo != ((1<<K)-1)) LT[rlo+1]--;
        }
        HT[lhi]++; if(rhi != ((1<<K)-1)) HT[rhi+1]--;
    }
    for(int i=0; i<(1<<K)-1; ++i) HT[i+1] += HT[i];
    for(int i=0; i<(1<<K); ++i) if(HT[i]) HT[i] = 1;
    for(int i=0; i<(1<<K)-1; ++i) LT[i+1] += LT[i];
    for(int i=0; i<(1<<K); ++i) if(LT[i]) LT[i] = 1;

    auto ans = LT;
    copy(HT.begin(), HT.end(), back_inserter(ans));
    for(int i=0; i<(1<<K)-1; ++i) HT[i+1] += HT[i];
    for(int i=0; i<(1<<K)-1; ++i) LT[i+1] += LT[i];

    auto SH = [&](int L, int R){ int ans = HT[R]; if(L) ans -= HT[L-1]; return ans;};
    auto SL = [&](int L, int R){ int ans = LT[R]; if(L) ans -= LT[L-1]; return ans;};

    for(auto [l, r, v]: V) if(!v)
    {
        uint32_t lhi = l >> K, llo = l & mask;
        uint32_t rhi = r >> K, rlo = r & mask;
        if(lhi == rhi) {
            if(SH(lhi, lhi) != 0 && SL(llo, rlo) != 0) return {};
        }
        else
        {
            if(SH(lhi, lhi) != 0 && SL(llo, (1<<K)-1) != 0) return {};
            if(SH(lhi+1, rhi-1) != 0 && SL(0, (1<<K)-1) != 0) return {};
            if(SH(rhi, rhi) != 0 && SL(0, rlo) != 0) return {};
        }
    }
    return ans;
}

int K, Q;
uint32_t L[MAXQ], R[MAXQ], V[MAXQ];

int main()
{
    scanf("%d%d", &K, &Q);
    for(int i=0; i<Q; ++i)
    {
        scanf("%" SCNu32 "%" SCNu32 "%" SCNu32, L+i, R+i, V+i);
    }
    vector<vector<int> > ans(16);
    for(int i=0; i<16; ++i)
    {
        vector<tuple<uint32_t, uint32_t, int> > P;
        for(int j=0; j<Q; ++j)
            P.emplace_back(L[j], R[j], (V[j]>>i)&1);
        ans[i] = solve(K, P);
        if(ans[i].size() == 0){ puts("impossible"); return 0;}
    }
    puts("possible");
    for(int i=0; i<(2<<K); ++i)
    {
        int r = 0; for(int j=0; j<16; ++j) if(ans[j][i]) r |= 1<<j;
        printf("%d\n", r);
    }
    return 0;
}