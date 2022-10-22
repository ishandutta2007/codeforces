#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int n, x, y;
vector<int> t_secret;
int i_secret, j_secret;
int nq;

int query(vector<int> pos)
{
    nq++;
    assert(nq <= 19);
    
    int was = pos.size();
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());
    assert((int)pos.size() == was);
    
    cout << "? " << pos.size() << " ";
    for (int x: pos)
    {
        assert(x >= 0 && x < n);
        cout << x + 1 << " ";
    }
    cout << endl;
    
    int answer = 0;
    if (!t_secret.empty())
    {
        for (int x: pos)
            answer ^= t_secret[x];
    }
    else
    {
        cin >> answer;
    }
    
    return answer;
}

void answer(int i, int j)
{
    if (i > j) swap(i, j);
    assert(i < j);
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);
    
    cout << "! " << i + 1 << " " << j + 1 << endl;
    
    if (!t_secret.empty())
    {
        bool ok = t_secret[i] == y && t_secret[j] == y;
        if (!ok)
        {
            printf("failure\n");
            abort();
        }
        else
        {
            printf("ok game n=%d\n", n);
        }
    }
    else exit(0);
}

void solve()
{
    int i_xor_j = 0;
    
    for (int bit = 0; bit < 10; bit++)
    {
        vector<int> pos;
        for (int i = 0; i < n; i++)
            if (i & (1 << bit))
                pos.push_back(i);
            
        if (pos.empty()) continue;
            
        int ans = query(pos);
        if (ans == y || ans == (x ^ y))
            i_xor_j ^= (1 << bit);
    }
    
    //printf("guessed %d versus %d\n", i_xor_j, i_secret ^ j_secret);
    //assert(i_xor_j == (i_secret ^ j_secret));
    
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++)
    {
        int j = i ^ i_xor_j;
        if (j >= 0 && j < n && i < j)
            pairs.emplace_back(i, j);
    }
    
    assert(pairs.size() <= 512);
    
    while (pairs.size() != 1)
    {
        //printf("now %d pairs\n", (int)pairs.size());
        int m = pairs.size() / 2;
        vector<int> pos;
        for (int t = 0; t < m; t++)
            pos.push_back(pairs[t].first);
        
        int ans = query(pos);
        if (ans == y || ans == (x ^ y))
        {
            pairs.erase(pairs.begin() + m, pairs.end());
        }
        else
        {
            pairs.erase(pairs.begin(), pairs.begin() + m);
        }
    }
    
    answer(pairs[0].first, pairs[0].second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> x >> y;
    solve();
    
#if 0
    while (true)
    {
        nq = 0;
        n = 1000;
        x = rand();
        do
        {
            y = rand();
        }
        while (x == y);
        
        assert(x >= 0 && y >= 0);
        
        t_secret.assign(n, x);
        
        int si = rand() % n;
        int sj = si;
        do
        {
            sj = rand() % n;
        }
        while (si == sj);
        
        t_secret[si] = t_secret[sj] = y;
        i_secret = si; j_secret = sj;
        
        solve();
    }
#endif
    
    return 0;
}