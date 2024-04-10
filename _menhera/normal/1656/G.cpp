#include<bits/stdc++.h>
using namespace std;
struct UFD
{
    vector<int> ufd;
    UFD(int n): ufd(n){iota(ufd.begin(), ufd.end(), 0); }
    int Find(int a){ if(a==ufd[a]) return a; return ufd[a] = Find(ufd[a]);}
    void Union(int a, int b){ ufd[Find(a)] = Find(b);}
};

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<int> A(N); for(int&x: A) cin >> x;
        bool ok = true;
        vector<vector<int>> cnt(N+1);
        for(int i=0;i<N;i++) cnt[A[i]].push_back(i);
        int odd = 0;
        for(int i=1; i<=N; ++i)
            if(cnt[i].size() % 2 == 1)
            {
                if(odd == 0) odd = i;
                else ok = false;
            }
        if(!ok)
        {
            cout <<"NO" << endl;
            continue;
        }
        vector<int> p(N);
        if(odd != 0)
        {
            auto it = cnt[odd].begin();
            if(*it == N/2) ++it;
            if(it == cnt[odd].end())
            {
                cout << "NO" << endl;
                continue;
            }
            p[N/2] = *it;
            cnt[odd].erase(it);
        }
        int x = 0;
        for(int i=1; i<=N; i++)
            for(int j=0; j<(int)cnt[i].size()/2; ++j)
            {
                p[x] = cnt[i][2*j];
                p[N-1-x] = cnt[i][2*j+1];
                x++;
            }
        UFD ufd(N);
        for(int i=0; i<N; ++i) ufd.Union(i, p[i]);
        for(int i=0; i<N-1-i; ++i)
        {
            if(ufd.Find(i) != ufd.Find(N-1-i))
                swap(p[i], p[N-1-i]);
            ufd.Union(i, N-1-i);
        }
        for(int i=0; i+1<N-1-(i+1); ++i)
        {
            if(ufd.Find(i) != ufd.Find(i+1))
            {
                int s1 = p[i], s4 = p[N-1-i];
                int s2 = p[i+1], s3 = p[N-1-(i+1)];
                p[i] = s2, p[N-1-(i+1)] = s1, p[N-1-i] = s3, p[i+1] = s4;
            }
            ufd.Union(i, i+1);
        }
        cout << "YES" << endl;
        for(auto x: p) cout << x+1 << " ";
        cout << endl;
    }
}