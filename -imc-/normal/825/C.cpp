#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long li;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    li k;
    cin >> n >> k;
    
    vector<li> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(all(a));
    
    int answer = 0;
    for (li x: a)
    {
        while (x > k * 2)
        {
            k *= 2;
            answer++;
        }
        
        k = max(k, x);
    }
    
    cout << answer << endl;
    
    return 0;
}