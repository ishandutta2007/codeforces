#include <bits/stdc++.h>

using namespace std;

typedef long long li;

// x, diff
pair<int, int> solve(int m, vector<int> a)
{
    if (a.empty())
        return make_pair(0, 1);
    
    if (a.size() == 1)
        return make_pair(a[0], 1);
    
    int n = a.size();
    unordered_set<int> nums;
    
    for (int i = 0; i < n; i++)
    {
        nums.insert(a[i]);
    }
    
    random_shuffle(a.begin(), a.end());
    
    for (int i = 1; i < n; i++)
    {
        int diff = a[i] - a[0];
        diff = (diff % m + m) % m;
        
        int cntUp = 0;
        for (int k = 1; ; k++)
            if (nums.count((a[0] + k * (li)diff) % m))
                cntUp++;
            else
                break;
        
        int cntDown = 0;
        for (int k = 1; ; k++)
            if (nums.count((a[0] + (m - k) * (li)diff) % m))
                cntDown++;
            else
                break;
            
        //printf("try %d base %d diff -> %d and %d\n", a[0], diff, cntDown, cntUp);
            
        if (cntUp + cntDown + 1 == (int)a.size())
        {
            auto answer = make_pair((int)((a[0] + (m - cntDown) * (li)diff) % m), diff);
            //printf("found %d %d\n", answer.first, answer.second);
            return answer;
        }
    }
    
    cout << -1 << endl;
    exit(0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    
    unordered_set<int> nums;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    pair<int, int> answer;
    if (m > 2 * n)
    {
        answer = solve(m, a);
    }
    else
    {
        //printf("solving reverse\n");
        vector<char> taken(m, false);
        for (int x: a)
            taken[x] = true;
        
        vector<int> b;
        for (int i = 0; i < m; i++)
            if (!taken[i])
                b.push_back(i);
            
        answer = solve(m, b);
        answer.first = (answer.first + answer.second * (li)b.size()) % m;
    }
    
    cout << answer.first << " " << answer.second << endl;
    
    return 0;
}