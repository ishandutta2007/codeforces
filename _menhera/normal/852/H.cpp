#include<bits/stdc++.h>
using namespace std;
int N, K;
int X[202];
int Y[202];
long long ccw(int a, int b, int c)
{
    int bx = X[b]-X[a], by = Y[b]-Y[a];
    int cx = X[c]-X[a], cy = Y[c]-Y[a];
    
    return 1LL*bx*cy-1LL*by*cx;
}

vector<int> lo[202], hi[202];
long long dp[202][202][202]; //head, head-1, chainsz
long long solve(int p)
{
    for(int i=p+1; i<N; ++i) lo[i].clear(), hi[i].clear();
    vector<int> pts;
    for(int i=p+1; i<N; ++i) pts.push_back(i);
    
    sort(pts.begin(), pts.end(), [&](int a, int b)
    {
        return ccw(p, a, b) > 0;
    });
    for(int i=0; i<(int)pts.size()-1; ++i)
    {
        hi[pts[i]].push_back(pts[i+1]);

        for(int j=i+2; j<(int)pts.size(); ++j)
        {
            if(ccw(pts[i], hi[pts[i]].back(), pts[j]) > 0)
            {
                hi[pts[i]].push_back(pts[j]);
            }
        }
    }
    for(int i=1; i<(int)pts.size(); ++i)
    {
        lo[pts[i]].push_back(pts[i-1]);
        for(int j=i-2; j>=0; --j)
            if(ccw(pts[i], lo[pts[i]].back(), pts[j]) < 0)
            {
                lo[pts[i]].push_back(pts[j]);
            }
    }
    memset(dp, 0xbf, sizeof dp);
    for(int i=p+1; i<N; ++i)
        for(auto c: hi[i])
        {
            dp[c][i][1] = ccw(p, i, c);
            //printf("%d %d %lld\n", c, i, ccw(p, i, c));
        }
    //puts("==");
    
    for(int k=2; k<=K-2; ++k)
    {
        for(int i=p+1; i<N; ++i)
        {
            if(lo[i].size() == 0) continue;
            int loptr = (int)lo[i].size()-1;
            int hiptr = 0;
            long long ans = -1e18;
            while(!(loptr == -1 && hiptr == (int)hi[i].size()))
            {
                auto adhi = [&]()
                {
                    dp[hi[i][hiptr]][i][k] = ans+ccw(p, i, hi[i][hiptr]);
                    ++hiptr;
                };
                auto adlo = [&]()
                {
                    ans = max(ans, dp[i][lo[i][loptr]][k-1]);
                    --loptr;
                };
                if(loptr == -1)
                    adhi();
                else if(hiptr == (int)hi[i].size())
                    adlo();
                else if(ccw(lo[i][loptr], i, hi[i][hiptr]) < 0)
                    adhi();
                else
                    adlo();
            }
        }
    }
    
    long long ans = 0;
    for(int i=p; i<N; ++i)
        for(int j=p; j<N; ++j)
            ans = max(ans, dp[i][j][K-2]);

    return ans;
}
int main()
{
    scanf("%d%d", &N, &K);
    vector<pair<int, int> > V;
    for(int i=0; i<N; ++i)
    {
        int x,y;scanf("%d%d", &x, &y); V.emplace_back(x, y);
    }
    sort(V.begin(), V.end());
    for(int i=0; i<N; ++i) tie(X[i], Y[i]) = V[i];
    long long ans = 0;
    for(int i=0; i<N-K+1; ++i)
        ans = max(ans, solve(i));
    printf("%lld.%lld0\n", ans/2, (ans%2)*5);
    return 0;
}