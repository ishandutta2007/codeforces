#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    string s;
    cin>>n>>k;
    cin>>s;
    int m = n/2;
    vector<int> kek(n, 0);
    int op = 0;
    int cl = 0;
    for (int i = 0; i<n; i++)
    {
        if (s[i]=='(') {kek[i] = op; op++;}
        else {kek[i] = cl; cl++;}
    }
    int k1 = k/2;
    for (int i = 0; i<n; i++) if (kek[i]<k1) cout<<s[i];
    
}