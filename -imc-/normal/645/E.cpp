#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<char> lettersSorted;
    for (int i = 0; i < k; i++)
        lettersSorted.push_back('a' + i);
    
    int l = s.size();
    for (int i = 0; i < l; i++)
    {
        char c = s[i];
        lettersSorted.erase(find(all(lettersSorted), c));
        lettersSorted.push_back(c);
    }
    
    for (int i = 0; i < n; i++)
    {
        s += *lettersSorted.begin();
        lettersSorted.push_back(*lettersSorted.begin());
        lettersSorted.erase(lettersSorted.begin());
    }
    
    map<char, ll> value;
    value['X'] = 1;
    ll sum = 1;
    
    const ll MOD = 1e9 + 7;
    
    for (int i = 0; i < (int)s.size(); i++)
    {
        ll v = (sum - value[s[i]] + MOD) % MOD;
        value[s[i]] += v;
        value[s[i]] %= MOD;
        sum += v;
        sum %= MOD;
    }
    
    cout << sum << endl;
    
    return 0;
}