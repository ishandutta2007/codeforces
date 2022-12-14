// And away I go.
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2009;
int n, Mn = N, A[N];
inline bool Ok(vector < int > vec)
{
    for (int i = 0; i < n + n; i ++)
        if (vec[i] != i)
            return 0;
    return 1;
}
inline void Solve(vector < int > vec, vector < int > w)
{
    if (Ok(vec))
        Mn = min(Mn, 0);
    for (int j = 0; j < (int)w.size(); j ++)
    {
        if (w[j] == 1) {
            for (int i = 0; i < n + n; i += 2)
                swap(vec[i], vec[i ^ 1]);
        }
        else if (w[j] == 2) {
            for (int i = 0; i < n; i ++)
                swap(vec[i], vec[i + n]);
        }
        if (Ok(vec))
            Mn = min(Mn, j + 1);
    }
}
int main()
{
    scanf("%d", &n);
    vector < int > vec;
    for (int i = 0; i < n + n; i ++)
        scanf("%d", &A[i]), vec.pb(A[i] - 1);
    for (int w = 1; w <= 2; w ++)
    {
        vector < int > vac;
        for (int i = 1; i <= N * 3; i ++)
        {
            if (i & 1) vac.pb(w);
            else vac.pb(3 - w);
        }
        Solve(vec, vac);
    }
    if (Mn == N)
        Mn = -1;
    return !printf("%d\n", Mn);
}