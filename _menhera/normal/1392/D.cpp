#include<bits/stdc++.h>
using namespace std;
char buf[252525];
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        scanf("%s", buf);
        char cur = buf[0];
        int cnt = 1;
        vector<pair<int, char>> V;
        for(int i=1; i<N; ++i)
        {
            if(cur != buf[i])
            {
                V.emplace_back(cnt, cur);
                cur = buf[i];
                cnt = 1;
            }
            else ++cnt;
        }
        V.emplace_back(cnt, cur);
        if(V.size()==1)
        {
            printf("%d\n", (N+2)/3);
        }
        else
        {
            if(V.back().second == V.front().second)
            {
                V.front().first += V.back().first;
                V.pop_back();
            }
            int ans = 0;
            for(auto [a, b]: V) ans += a/3;
            printf("%d\n", ans);
        }
    }
}