#include <bits/stdc++.h>

using namespace std;

int get(int x)
{
    int cnt = 0;
    while(x % 5 == 0)
    {
        cnt++;
        x /= 5;
    }
    return cnt;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    int z = 0;
    vector<int> ans;
    int cc = 0;
    while(z <= k)
    {
        if(z == k)
            ans.push_back(cc);
        cc++;
        if(cc % 5 == 0)
            z += get(cc);
    }
    cout << ans.size() << "\n";
    for(auto it: ans)
        cout << it << ' ';
}