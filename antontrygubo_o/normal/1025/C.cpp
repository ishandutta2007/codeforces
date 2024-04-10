#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 998244353;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin>>s;
    int n = s.length();
    s=s+s;
    int best = 1;
    int current = 1;
    for (int i = 1; i<2*n; i++)
    {
        if (s[i]!=s[i-1]) current++;
        else current = 1;
        best = max(best, current);
    }
    cout<<min(best, n);
    
}