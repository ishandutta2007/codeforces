#include <bits/stdc++.h>

using namespace std;

typedef long long li;

#define all(v) (v).begin(), (v).end()

int main()
{
    int n, k;
    cin >> n >> k;
    
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    vector<li> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    li base = *min_element(all(a));
    
    li answer = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % k != a[0] % k)
        {
            cout << -1 << endl;
            return 0;
        }
        else
            answer += (a[i] - base) / k;
        
    cout << answer << endl;
    
    return 0;
}