#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using ld = long double;



#define mp make_pair

int p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}


mt19937 rnd(time(0));


const int N = 1000005;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}




/*struct DSU
{
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/


int main()
{
    int n, m;
    cin>>n>>m>>p;
    init();

    vector<int> cnt(m+1), answer(m+1);

    cnt[0] = 1;
    cnt[1] = 2;

    for (int i = 2; i<=m; i++)
    {
        for (int j = 0; j<i; j++)
        {
            int ways = mul(C(i-1, j), mul(cnt[j], cnt[i-j-1]));
            cnt[i] = add(cnt[i],  mul(i+1, ways));
            answer[i] = add(answer[i],  mul(i+1, mul(C(i-1, j),  mul(answer[j], cnt[i-j-1]))));
            answer[i] = add(answer[i],  mul(i+1, mul(C(i-1, j),  mul(cnt[j], answer[i-j-1]))));
            answer[i] = add(answer[i], mul(ways, j*(j+1)/2 + (i-j-1)*(i-j)/2));
        }
    }

    vector<vector<int>> dp_cnt(n+1, vector<int>(m+1)), dp_answer(n+1, vector<int>(m+1));

    /*for (int i = 0; i<=m; i++)
    {
        cout<<i<<": "<<cnt[i]<<' '<<answer[i]<<endl;
    }*/

    dp_cnt[0][0] = 1;

    for (int i = 1; i<=n; i++)
    {
        for (int j = 0; j<=min(m, i); j++)
        {

            if (i==j)
            {
                dp_cnt[i][j] = cnt[j];
                dp_answer[i][j] = answer[j];
                continue;
            }

            for (int k = 0; k<=j; k++)
            {
                dp_cnt[i][j] = add(dp_cnt[i][j], mul(C(j, k), mul(cnt[k], dp_cnt[i-k-1][j-k])));
                dp_answer[i][j] = add(dp_answer[i][j], mul(C(j, k), mul(cnt[k], dp_answer[i-k-1][j-k])));
                dp_answer[i][j] = add(dp_answer[i][j], mul(C(j, k), mul(answer[k], dp_cnt[i-k-1][j-k])));
            }
        }
    }

    cout<<dp_answer[n][m];

}

/*
5
2
2 3
2 3 1
1 2 2 1
3 1 3 2 3
 */