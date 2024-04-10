#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > arr;
vector<vector<int> > brr;
map<pair<int, int> , bool> m;
int N, M;
bool solve(int l, int r)
{
    for(int i=0; i<M; ++i)
    {
        if(brr[l-1][i]==brr[r-1][i]) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0; i<N; ++i)
    {
        vector<int> a;
        vector<int> b;
        for(int j=0; j<M; ++j)
        {
            int t;
            scanf("%d",&t);
            a.push_back(t);
            if(i==0) b.push_back(0);
            else b.push_back(brr[i-1][j]+(int)(arr[i-1][j]>t));
        }
        arr.push_back(a);
        brr.push_back(b);
    }
    int K;
    scanf("%d", &K);
    for(int i=0; i<K; ++i)
    {
        int l, r; scanf("%d%d",&l,&r);
        if(m.count(make_pair(l, r))==0) 
            m[make_pair(l,r)] = solve(l,r);
        puts( m[make_pair(l,r)]?"Yes":"No");
        
        
        
    }
}