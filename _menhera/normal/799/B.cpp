#include<bits/stdc++.h>
using namespace std;
int p[202020];
int a[202020];
int b[202020];
set<pair<int, int> > S[3];
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", p+i);
    for(int i=0; i<N; ++i) scanf("%d", a+i);
    for(int i=0; i<N; ++i) scanf("%d", b+i);
    for(int i=0; i<N; ++i)
    {
        S[a[i]-1].insert(make_pair(p[i], i));
        if(a[i]!=b[i]) S[b[i]-1].insert(make_pair(p[i], i));
    }
    int M;
    scanf("%d", &M);
    for(int i=0; i<M; ++i)
    {
        int x;
        scanf("%d", &x);
        --x;
        if(S[x].size()==0)
        {
            printf("-1 ");
        }    
        else
        {
            auto v = *(S[x].begin());
            printf("%d ", v.first);
            if(S[0].find(v)!=S[0].end())S[0].erase(v);
            if(S[1].find(v)!=S[1].end()) S[1].erase(v);
             if(S[2].find(v)!=S[2].end())S[2].erase(v);
        }
        
    }
    return 0;
}