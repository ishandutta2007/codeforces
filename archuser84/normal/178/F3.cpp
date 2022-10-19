///
///    I have a dream and a piano
///

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

const int N = 2010;
int A[500*N][26]; int cc=1;
int cnt[500*N];

void add(string s)
{
    int i = 0;
    for(char c : s)
    {
        if(!A[i][c-'a']) A[i][c-'a'] = cc++;
        i = A[i][c-'a'];
    }
    ++cnt[i];
}

void dfs(int vv, int h, vector<ll>& v)
{
    if(cnt[vv]){
        v.push_back(0);
        Loop(i,0,cnt[vv])
            v.push_back(v.back()+1ll*i*h);
    }
    Loop(i,0,26)
    {
        if(!A[vv][i]) continue;
        if(v.empty()) dfs(A[vv][i],h+1,v);
        else{
            vector<ll> u;
            dfs(A[vv][i], h+1, u);
            vector<ll> nv(u.size()+v.size()-1);
            Loop(i,0,v.size())
                Loop(j,0,u.size())
                    nv[i+j] = max(nv[i+j],v[i]+u[j]+1ll*i*j*h);
            v = nv;
        }
    }
}

int n, k;

int main()
{
    FAST;
    cin >> n >> k;
    while(n--)
    {
        string s;
        cin >> s;
        add(s);
    }
    vector<ll> v;
    dfs(0,0,v);
    cout << v[k] << '\n';
}