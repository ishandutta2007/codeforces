#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    k = min(k, n / 2);
    
    ll answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (i < k || i >= n - k)
            answer += n - i - 1;
        else
            answer += k;
    }
    
    cout << answer << endl;
    
    return 0;
}