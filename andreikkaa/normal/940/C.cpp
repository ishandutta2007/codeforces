#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    if(n < k)
    {
        char c = s[0];
        for(int i = 1; i < n; ++i)
        {
            c = min(c, s[i]);
        }
        cout << s << string(k - n, c) << endl;
    }
    else
    {
        string t = s;
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        
        s.erase(s.end() - (n - k), s.end());
        
        for(int i = k - 1; i >= 0; --i)
        {
            if(s[i] == t[t.size() - 1])
            {
                s[i] = t[0];
            }
            else
            {
                s[i] = *upper_bound(t.begin(), t.end(), s[i]);
                break;
            }
        }
        
        cout << s << endl;
    }
}