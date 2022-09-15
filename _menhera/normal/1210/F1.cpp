#include <bits/stdc++.h>
using namespace std;

const int N = 6;
const int MOD = (int)1e9+7;
int ipow(int a, int b)
{
    if(b==0) return 1;
    int ans = ipow(a, b/2); ans = 1LL*ans*ans%MOD;
    if(b&1) ans = 1LL*ans*a%MOD;
    return ans;
}
int modInv(int a){ return ipow(a, MOD-2); }
int p[N][N];

int solve()
{
    // Choose(N, N/2)
    int NCN2 = 1; for(int i=N/2+1; i<=N; ++i) NCN2 *= i; for(int i=1; i<=N/2; ++i) NCN2 /= i;
    // cerr << NCN2 << endl;
    vector<vector<int> > fg(2, vector<int>(1<<(NCN2)));
    for(int msk=0; msk<(1<<(N*N/2)); ++msk)
    {
        for(int side=0; side<2; ++side)
        {
            int prob = 1;
            for(int r=0; r<N; ++r)
                for(int c=0; c<N/2; ++c)
                {
                    int i = c*N+r;
                    int pr;
                    if(msk & (1<<i))
                        pr = p[r][c+side*N/2];
                    else pr = MOD+1-p[r][c+side*N/2]; 
                    prob = 1LL*prob*pr%MOD;
                }
            vector<int> choice(N); fill(choice.begin()+N/2, choice.end(), 1);
            if(side) reverse(choice.begin(), choice.end());
            auto Do = [&](){
                if(side) return prev_permutation(choice.begin(), choice.end());
                else return next_permutation(choice.begin(), choice.end());
            };
            int comb_idx = 0, comb_mask = 0;
            do
            {
                int mask = 0; for(int i=0; i<N; ++i) if(choice[i]) mask |= 1<<i;
                bool marriage = true;
                for(int i=0; i<(1<<(N/2)); ++i)
                {
                    int tot_mask = 0;
                    for(int j=0; j<N/2; ++j) if(i&(1<<j)) tot_mask |= msk >> (j*N);
                    tot_mask &= mask;
                    if(__builtin_popcount(tot_mask) < __builtin_popcount(i)) {
                        marriage = false; break;
                    }
                }
                if(marriage) comb_mask |= 1<<comb_idx;
                ++comb_idx;
            } while (Do());
            //if(prob && side ) cerr << side << " " << msk << " " << comb_mask << " " << prob << endl;
            fg[side][comb_mask] += prob; if(fg[side][comb_mask] >= MOD) fg[side][comb_mask] -= MOD;
        }
    }
    for(int i=0; i<NCN2; ++i)
        for(int j=0; j<(1<<NCN2); ++j)
            if(!(j&(1<<i)))
            {
                fg[1][j|(1<<i)] += fg[1][j];
                if(fg[1][j|(1<<i)] >= MOD) fg[1][j|(1<<i)] -= MOD;
            }
    int ans = 0;
    for(int i=0; i<(1<<NCN2); ++i)
        ans = (ans + 1LL * fg[0][i] * fg[1][((1<<NCN2)-1)^i])%MOD;
    return (MOD+1-ans)%MOD;
}

int main()
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
    {
        int t; scanf("%d", &t);
        p[i][j] = 1LL*t*modInv(100)%MOD;
    }
    for(int i=n; i<N; ++i) p[i][i] = 1;
    printf("%d\n", solve());
}