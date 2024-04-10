#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; string s, t; cin >> N >> s >> t;
        int s1 = 0, t1 = 0, eq = 0, df = 0;
        for(int i=0; i<N; ++i)
        {
            if(s[i] == '1') ++s1;
            if(t[i] == '1') ++t1;
            if(s[i] == t[i]) ++eq;
            else ++df;
        }
        int ans = N+1;
        if(s1 == t1) ans = min(ans, df);
        if(s1+t1 == N+1) ans = min(ans, eq);
        if(ans == N+1) ans = -1;
        cout << ans << '\n';
    }
}