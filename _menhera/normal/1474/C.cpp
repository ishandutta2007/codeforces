#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > solve(const vector<int>& A, int X)
{
    int N = A.size() / 2; multiset<int> S(A.begin(), A.end());
    vector<pair<int, int> > ans, nv;
    for(int i=0; i<N; ++i)
    {
        auto it = prev(S.end()); 
        int v = *it; S.erase(it);
        int u = X-v;
        auto it2 = S.find(u);
        if(it2 == S.end()) return nv;
        ans.emplace_back(v, u);
        X = v;
        S.erase(it2);
    }
    return ans;
}

int main()
{
    int T; scanf("%d", &T); while(T--)
    {
        int N; scanf("%d", &N);
        vector<int> A(2*N);
        for(int i=0; i<2*N; ++i) scanf("%d", &A[i]);
        sort(A.begin(), A.end());
        
        
        bool ok = false;
        
        for(int i=0; i<2*N-1; ++i)
        {
            vector<pair<int, int> > ans = solve(A, A[i]+A[2*N-1]);
            if(ans.size())
            {
                puts("YES");
                printf("%d\n", A[i]+A[2*N-1]);
                for(auto [a, b]: ans) printf("%d %d\n", a, b);
                ok = true;
                break;
            }
        }
        if(!ok) puts("NO");
        
    }
}