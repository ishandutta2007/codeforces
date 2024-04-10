#include <bits/stdc++.h>
using namespace std;

int A[6];
int N;
int B[101010];
int used[101010];
int ucnt = 0;
int main()
{
    for(int i=0; i<6; ++i)
        scanf("%d", A+i);
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
        scanf("%d", B+i);

    vector<pair<int, int> > V;
    for(int i=0; i<N; ++i)
        for(int j=0; j<6; ++j)
            V.emplace_back(B[i]-A[j], i);
    sort(V.begin(), V.end());

    int ans = 0x3f3f3f3f;

    // [lo, hi), starts with [-1, 0): nothing
    int hi = 0;
    for(int lo=0; lo < (int)V.size(); ++lo)
    {
        while(hi < (int)V.size() && ucnt != N)
        {
            // adding hi
            int idx = V[hi].second;
            if(used[idx] == 0) ++ucnt;
            used[idx]++;
            ++hi;
        }
        //printf("%d %d %d %d\n", lo, V[lo].first, hi-1, V[hi-1].first);
        if(ucnt == N)
            ans = min(ans, V[hi-1].first-V[lo].first);


        // removing lo
        int idx = V[lo].second;
        if(used[idx] == 1) --ucnt;
        used[idx]--;
    }

    printf("%d\n", ans);
}