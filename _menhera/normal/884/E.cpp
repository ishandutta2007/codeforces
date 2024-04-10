#include <bits/stdc++.h>
using namespace std;

struct UF
{
    vector<int> ufd;
    UF(int N): ufd(N) { iota(ufd.begin(), ufd.end(), 0); };
    void Set(int a, int v) { ufd[a] = v; }
    int Find(int a) { if(a==ufd[a]) return a; return ufd[a] = Find(ufd[a]); };
    bool Union(int a, int b) {
        a = Find(a); b = Find(b);
        if(a>b) swap(a, b);
        ufd[a] = b; return a!=b;
    }
};


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;

    int ans = 0;
    vector<bool> p(M);
    UF uf(2*M);
    for(int i=0; i<N; ++i)
    {
        vector<bool> q(M);
        string s; cin >> s;
        for(int j=0; j<M/4; ++j)
        {
            int v;
            if('0' <= s[j] && s[j] <= '9') v = s[j] - '0';
            else v = s[j] - 'A' + 10;
            q[j*4] = v&8; q[j*4+1] = v&4; q[j*4+2] = v&2; q[j*4+3] = v&1;
        }
        for(auto c: q) if(c) ++ans;
        for(int i=0; i<M; ++i) {
            if(p[i] && q[i]) if(uf.Union(i, i+M)) --ans;
            if(i != M-1 && q[i] && q[i+1]) if(uf.Union(i+M, i+1+M)) --ans;
        }
        UF nuf(2*M); for(int i=0; i<M; ++i) nuf.Set(i, uf.Find(i+M)-M);
        uf = nuf; p = q;
    }
    cout << ans << endl;
}