#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    multiset<int> pos;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos.insert(x);
    }
    
    auto it1 = pos.lower_bound(b + 1);
    auto it2 = pos.lower_bound(c);
    
    int answer = 0;
    while (it1 != it2)
    {
        it1++;
        answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}