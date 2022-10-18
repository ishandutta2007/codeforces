#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(auto &it: a)
        cin >> it;
    vector<int> normalized;
    rep:
    int carry = 0;
    for(int i = 0; i <= n; i++)
    {
        //cout << a[i] + carry << endl;
        normalized.push_back(abs((a[i] + carry) % 2));
        carry = (a[i] + carry - (a[i] + carry < 0)) / 2;
    }
    int ll = carry >= 0 ? 1 : -1;
    if(ll == -1)
    {
        normalized.clear();
        for(auto &it: a)
            it = -it;
        goto rep;
    }
    while(carry)
    {
        normalized.push_back(abs(carry) % 2);
        carry = (carry - (carry < 0)) / 2;
    }
    while(normalized.back() == 0)
        normalized.pop_back();
    /*cout << "OK" << endl;
    cout << ll << ' ';
    for(auto it: normalized)
        cout << it;
    cout << endl;*/
    int ans = 0;
    for(int i = 0; i <= n; i++)
    {
        if(i + 40 >= normalized.size())
        {
            int need = 0;
            for(int j = i; j < normalized.size(); j++)
            {
                need += normalized[j] << (j - i);
            }
            need *= -ll;
            if(i == n && a[i] + need == 0)
                continue;
            if(a[i] + need <= k && a[i] + need >= -k)
                ans++;
            //cout << i << ": " << need << endl;
        }
        if(normalized[i] == 1)
            break;
    }
    cout << ans << "\n";
    return 0;
}