#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    map<int, int> cnt;
    for(auto &it: a)
    {
        cin >> it;
        cnt[it]++;
    }
    int ans = max(2, cnt[0]);
    int rt[n];
    int sz = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            while(sz > 0)
                cnt[rt[--sz]]++;
            if(i == j)
                continue;
            int A = a[i];
            int B = a[j];
            if(A == 0 && B == 0)
                continue;
            cnt[A]--;
            cnt[B]--;
            int cn = 2;
            while(true)
            {
                auto &it = cnt[A + B];
                if(it == 0)
                    break;
                cn++;
                it--;
                rt[sz++] = A + B;
                int C = A + B;
                A = B;
                B = C;
            }
            cnt[a[i]]++;
            cnt[a[j]]++;
            ans = max(ans, cn);
        }
    cout << ans << "\n";
}