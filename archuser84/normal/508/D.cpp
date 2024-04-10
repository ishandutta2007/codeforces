///                                                            ///
///    "Excuse me... What did you say about my hair?!"         ///
///                                                            ///
///                                    -Josuke Higashikata     ///

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int sigma = 256;
const int N = 100'010;
vector<int> A[sigma*sigma];
vector<int> T[sigma*sigma];
int n;

inline int my_mp(int a, int b){return sigma*a+b;}

void add_edge(int a, int b)
{
    A[a].push_back(b);
    T[b].push_back(a);
}

void euler(int u, string& s)
{
    vector<int> ans;
    int v = u;
    ans.push_back(v);
    while(1)
    {
        if(A[v].empty()) break;
        int t = v;
        v = A[v].back();
        ans.push_back(v);
        A[t].pop_back();
    }
    if(ans.size() == 1)
    {
        s.push_back(u%sigma);
        return;
    }
    for(int x : ans)
        //cerr << char(x/256) << char(x%256) << '\n',
        euler(x, s);
}

int main()
{
    FAST;
    cin >> n;
    string s;
    int u;
    Loop(i,0,n)
    {
        cin >> s;
        add_edge(my_mp(s[0], s[1]), my_mp(s[1], s[2]));
        u = my_mp(s[0], s[1]);
    }
    int bad=0;
    Loop(i, 0,sigma*sigma)
    {
        if(A[i].size() > T[i].size())
            u = i;
        bad += abs<int>(A[i].size() - T[i].size());
    }
    if(bad > 2) Kill("NO");
    string ans;
    ans.push_back(u/sigma);
    euler(u, ans);
    if(ans.size() != n+2) Kill("NO");
    cout << "YES\n" << ans << '\n';
}