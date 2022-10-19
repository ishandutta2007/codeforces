#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        int ptr= t.size()-1;
        vector<int> pos;
        vector<int>ok(s.size(),1);
        for(int i = s.size()-1;i>=0;--i)
        {
            if(ptr <0) break;
            if(s[i] ==t[ptr])
            {
                ok[i]=0;
                pos.pbc(i);
                --ptr;
            }
        }
        if(ptr >=0)
        {
            cout<<"NO\n";
            continue;
        }
        vector<vector<int>> suf(s.size(), vector<int> (26));
        for(int i= s.size()-1;i>=0;--i)
        {
            if(i+1<s.size())
            {
                for(int j=0;j< 26;++j) suf[i][j] += suf[i+1][j];
            }
            if(ok[i]) suf[i][s[i]-  'A']++;
        }
        bool tok=1;
        for(int i = 0;i< pos.size();++i)
        {
            int id= pos[i];
            if( id+1< s.size() && suf[id+1][s[pos[i]]- 'A']) tok=0;
        }
        if(tok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}