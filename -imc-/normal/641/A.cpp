#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    string s;
    
    cin >> n >> s;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int pos = 0;
    
    vector<char> was(n);
    while (true)
    {
        if (pos < 0 || pos >= n)
            break;
        
        if (was[pos])
        {
            printf("INFINITE\n");
            return 0;
        }
        
        was[pos] = true;
        pos = pos + (s[pos] == '<' ? -1 : 1) * a[pos];
    }
    
    printf("FINITE\n");
    return 0;
}