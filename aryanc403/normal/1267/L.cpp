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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int n, l, k;
    cin >> n >> l >> k;
    
    string tmp;
    cin >> tmp;
    
    sort(tmp.begin(), tmp.end());
    
    vector<string> strings(n);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != l; ++j)
            strings[i] += ' ';
    
    int eq = 0;
    int idx = 0;
    for (int j = 0; j != l; ++j)
    {
        for (int i = eq; i != k; ++i)
            strings[i][j] = tmp[idx++];
        
        for (int i = eq; i != k; ++i)
            if (strings[i][j] == strings[k - 1][j])
            {
                eq = i;
                break;
            }
    }
    
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != l; ++j)
            if (strings[i][j] == ' ')
                strings[i][j] = tmp[idx++];
    
    for (string & ans : strings)
        cout << ans << '\n';
    
	return 0;
}