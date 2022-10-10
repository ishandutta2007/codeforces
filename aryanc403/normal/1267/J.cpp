#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <cassert>
using namespace std;

set<int> helper(int n)
{
    set<int> ret;
    
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
            ret.insert(-(n / i));
        ret.insert(-(n / i + 1));
    }
    
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int> cnt(n);
    
    for (int i = 0; i != n; ++i)
    {
        int x; 
        cin >> x;
        
        cnt[x - 1]++;
    }
    
    vector<int> cnts;
    for (int x : cnt)
        if (x)
            cnts.push_back(x);
    
    int m = n;
    sort(cnts.begin(), cnts.end());
    
    for (int s : helper(cnts[0]))
    {
        s = -s;
        if (s == 1)
            break;
        
        bool ok = 1;
        
        int tmp = 0;
        
        for (int count : cnts)
        {
            int a, b;
            if (count % s == 0)
                a = 0, b = count / s;
            else if (count % s + count / (s - 1) < s)
                ok = 0;
            else
            {
                a = s - count % s;
                b = (count - a * (s - 1)) / s;
            }
            
            if (ok)
                assert(a * (s - 1) + b * s == count);
            
            tmp += a + b;
        }
        
        if (!ok)
            continue;
        
        m = tmp;
        break;
    }
    
    cout << m << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int t;
    for (cin >> t; t--;)
        solve();
    
	return 0;
}