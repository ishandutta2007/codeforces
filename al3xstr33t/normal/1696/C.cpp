#include<bits/stdc++.h>

using namespace std;

//const int maxN = 1e6 + 100;
//int N, a[maxN];

vector<pair<int, long long>> compress(vector<pair<int, long long>> b) {
    vector<pair<int, long long>> a;
    for (auto it : b) {
        if (!a.empty() && a.back().first == it.first)
            a.back().second += it.second;
        else
            a.push_back(it);
    }
    return a;
}

vector<pair<int, long long>> push(vector<int> b, int M) {
    vector<pair<int, long long>> ans;
    for (auto it : b) {
        int f = 1, val = it;
        while (val % M == 0)
            val /= M, f *= M;
        ans.push_back(make_pair(val, (long long) f));
    }
    return compress(ans);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int n, M, l;
    scanf ("%d %d", &n, &M);
    vector<int> curr(n, 0);
    for (int i=0; i<n; i++)
        scanf("%d", &curr[i]);
    auto b = push(curr, M);
    scanf("%d", &l);
    curr.resize(l);
    for (int i=0;i<l;i++)
        scanf("%d", &curr[i]);
    auto c = push(curr, M);
    bool ok = 1;
    if (b.size() != c.size()) ok = 0;
    else {
        for (int i=0; i<b.size();i++)
            ok &= (b[i].first == c[i].first && b[i].second == c[i].second);
    }
    if (ok) printf("Yes\n");
    else printf("No\n");
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/