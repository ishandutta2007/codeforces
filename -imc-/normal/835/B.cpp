#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    li k;
    cin >> k;
    
    string s;
    cin >> s;
    
    vector<int> nd(10);
    
    li sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - '0';
        nd[s[i] - '0']++;
    }
    
    if (sum >= k)
    {
        cout << "0\n";
        return 0;
    }
    
    li answer = 0;
    for (int i = 0; i < 9; i++)
    {
        li ct = (k - sum + 9 - i - 1) / (9 - i);
        int take = min(ct, (li)nd[i]);
        answer += take;
        sum += (9 - i) * take;
        if (sum >= k) break;
    }
    
    cout << answer << '\n';
    
    return 0;
}