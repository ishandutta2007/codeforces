#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int answer = 0;
    string s;
    while (cin >> s)
    {
        int x = 0;
        for (char c: s)
            if (isupper(c))
                x++;
            
        answer = max(answer, x);
    }
    
    cout << answer << endl;
    
    return 0;
}