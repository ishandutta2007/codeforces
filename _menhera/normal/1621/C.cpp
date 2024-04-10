#include <bits/stdc++.h>

using namespace std;

int main() {
    auto Q = [&](int x)
    {
        cout << "? " << x << endl;
        int v; cin >> v; return v;
    };
    int T; cin >> T; while(T--) {
        int N; cin >> N;
        vector<bool> vis(N+1); vector<int> p(N+1);
        for(int i=1; i<=N; ++i) if(!vis[i])
        {
            vector<int> V;
            while(true)
            {
                int n = Q(i); V.push_back(n);
                if(vis[n]) break; else vis[n] = 1;
            }
            for(int i=0; i<(int)V.size()-1; ++i)
                p[V[i]] = V[i+1];
        }
        cout << "!";
        for(int i=1; i<=N; ++i) cout << " " << p[i];
        cout << endl;
    }
}