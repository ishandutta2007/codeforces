#include<bits/stdc++.h>
using namespace std;


const int MAXN = 2e5;
int l[MAXN], r[MAXN];

int H(int a)
{
    int ans = 0;
    if(l[a] != -1) ans = max(ans, H(l[a]));
    if(r[a] != -1) ans = max(ans, H(r[a]));
    return ans+1;
}

int calc(const vector<int>& V, int from, int to)
{
    if(from == to) return 0;
    vector<int> st; 
    for(int i=from; i<to; ++i)
    {
        int lp = -1;
        while(!st.empty() && V[st.back()] > V[i])
        {
            lp = st.back(); st.pop_back();
        }
        l[i] = lp; r[i] = -1;
        if(!st.empty()) r[st.back()] = i;
        st.push_back(i);
    }
    return H(st.front());
}

int f(const vector<int> &V, int thres)
{
    int lo = 0; // [0, lo) <= thres
    int hi = (int)V.size()+1; // [0, hi) > thres
    while(lo+1!=hi)
    {
        int mi = (lo+hi)/2;
        if(calc(V, 0, mi) <= thres) lo = mi;
        else hi = mi;
    }
    if(calc(V, lo, (int)V.size()) <= thres) return lo;
    else return -1;
}

pair<int, int> solve(const vector<int>& V)
{
    int lo = -1; // impossible
    int hi = (int)V.size(); // possible
    while(lo+1!=hi)
    {
        int mi = (lo+hi)/2;
        if(-1 != f(V, mi)) hi = mi;
        else lo = mi;
    }
    return make_pair(f(V, hi), hi);
}

int main()
{
    int N; scanf("%d", &N);
    vector<int> V(N); for(int i=0; i<N; ++i) scanf("%d", &V[i]);
    int idx = find(V.begin(), V.end(), 1)-V.begin();
    vector<int> U;
    for(int i=idx+1; i<N; ++i) U.push_back(V[i]);
    for(int i=0; i<idx; ++i) U.push_back(V[i]);
    auto [a, v] = solve(U);
    printf("%d %d\n", v+1, (a+idx+1)%N);
}