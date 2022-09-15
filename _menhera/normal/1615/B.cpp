#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int K = 200000;
    vector<int> V[20];
    for(int i=0; i<20; ++i)
    {
        V[i].resize(K+1);
        for(int j=1; j<=K; ++j)
        {
            V[i][j] = V[i][j-1];
            if(!(j&(1<<i))) V[i][j]++;
        }
    }

    int T; cin >> T; while(T--)
    {
        int L, R; cin >> L >> R;
        int ans = R-L+1;
        for(int i=0; i<20; ++i)
        {
            ans = min(ans, V[i][R]-V[i][L-1]);
        }
        cout << ans << '\n';
    }
}