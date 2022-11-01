#include <bits/stdc++.h>

using namespace std;

int n;
map<int,int> cnt;
long long ans;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for(int j = 0; j < 31; j++)
        {
            int y = (1 << j);
            if(y <= x) continue;
            y -= x;
            ans += cnt[y];
        }
        cnt[x]++;
    }
    cout << ans;
}