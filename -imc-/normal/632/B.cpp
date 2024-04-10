#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll sum;

ll getMax(vector<ll> p)
{
    ll answer = 0;
    
    ll s1 = 0, s2 = 0;
    vector<ll> sufVec(n);
    for (int i = n - 1; i >= 0; i--)
        sufVec[i] = (i == n - 1 ? 0 : sufVec[i + 1]) + (p[i] >= 0 ? p[i] : 0);
    
    for (int i = 0; i < n; i++)
    {
        if (p[i] >= 0) s1 += p[i];
        else s2 += -p[i];
        
        answer = max(answer, max(s1, s2) + (i == n - 1 ? 0 : sufVec[i + 1]));
    }
    
    return answer;
}

int main()
{
    cin >> n;
    
    vector<ll> p(n);
    string s;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    cin >> s;
    
    for (int i = 0; i < n; i++)
    {
        sum += p[i];
        if (s[i] == 'A')
            p[i] = -p[i];
    }
    
    ll answer = getMax(p);
    reverse(p.begin(), p.end());
    answer = max(answer, getMax(p));
    
    cout << answer << endl;
    
    return 0;
}