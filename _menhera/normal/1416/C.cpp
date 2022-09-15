#include <bits/stdc++.h>
using namespace std;



int main()
{
    int N; scanf("%d", &N);
    vector<int> arr;
    for(int i=0; i<N; ++i)
    {
        int t; scanf("%d", &t);
        arr.push_back(t);
    }
    vector<vector<int> > V;
    V.push_back(arr);
    int ans = 0;
    long long cnt = 0;
    for(int i=29; i>=0; --i)
    {
        vector<vector<int> > U;
        long long tinv = 0, tsinv = 0;
        for(const auto& v: V)
        {
            int zcnt = 0, ocnt = 0;
            for(int a: v)
            {
                if(a&(1<<i))
                {
                    tsinv += zcnt;
                    ocnt++;
                }
                else
                {
                    tinv += ocnt;
                    zcnt++;
                }
            }
        }
        if(tsinv < tinv) ans ^= (1<<i);
        cnt += min(tsinv, tinv);
        for(const auto&v: V)
        {
            vector<int> v1, v2;
            for(int a: v)
            {
                if(a&(1<<i)) v1.push_back(a);
                else v2.push_back(a);
            }
            if(v1.size()) U.push_back(v1);
            if(v2.size()) U.push_back(v2);
        }
        V = U;
    }
    printf("%lld %d\n", cnt, ans);
}