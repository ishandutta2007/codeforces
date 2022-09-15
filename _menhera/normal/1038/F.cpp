#include<bits/stdc++.h>
using namespace std;


const int MAXN = 40;

//[0, i) matched length |s| with T or F
//first |s|-i character, last i character matched length |s| with T or F
using State = pair<uint64_t, uint64_t>;
State OK = {-1, -1};

State trans(int N, const string& s, const State& st, int idx, char next)
{
    int M = (int)s.size();
    if(st == OK) return OK;
    State n = {0, st.second};
    n.first |= 1;
    for(int i=0; i<M; ++i)
    {
        uint64_t mask = ((uint64_t)1)<<i;
        if( (st.first&mask) && s[i] == next) n.first |= (((uint64_t)1)<<(i+1));
    }
    if(n.first & (((uint64_t)1)<<M)) return OK;

    for(int i=0; i<M; ++i)
    {
        uint64_t mask = ((uint64_t)1)<<i;
        if(idx < M-i && s[i+idx] != next) n.second &= ~mask;
        if(idx >= N-i && s[idx-(N-i)] != next) n.second &= ~mask;
    }
    if(idx == N-1 && n.second) return OK;
    return n;
}

long long solve(int N, string s)
{
    map<State, long long> M;
    M[{1, ((((uint64_t)1)<<s.size())-1)}] = 1;
    for(int i=0; i<N; ++i)
    {

        map<State, long long> M2;
        for(auto [a, b]: M)
        {
            cerr << a.first << " " << a.second << " " << b << endl;
            M2[trans(N, s, a, i, '0')] += b;
            M2[trans(N, s, a, i, '1')] += b;
        }
        cerr << endl;
        M = M2;
    }
    for(auto [a, b]: M) cerr << a.first << " " << a.second << " " << b << endl;
    cerr << endl;
    return M[OK];
}

int main()
{
    int N; string s;
    cin >> N >> s;
    cout << solve(N, s) << endl;
}