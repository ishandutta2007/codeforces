#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast","unroll-loops")
#pragma GCC target ("avx","avx2","popcnt")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> p(27,0);
    vector<int> pos(27,0);
    for(int i=1;i<=26;i++)
    {
        cin >> p[i];
        pos[p[i]]=i;
    }
    string s,t;
    cin >> s >> t;
    int n=s.size();
    int m=t.size();
    s="$"+s;
    t="$"+t;
    const int N=200001;
    bitset<N> res;
    res.set();
    bitset<N> opt[27];
    for(int i=1;i<=26;i++)
    {
        for(int j=1;j<=m;j++) opt[i][j]=(t[j]-'a'+1==i||pos[t[j]-'a'+1]==i);
    }
    for(int i=1;i<=n;i++) res&=(opt[s[i]-'a'+1]>>(i-1));
    for(int i=1;i<=m-n+1;i++) cout << res[i];
    cout << "\n";
    return 0;
}