#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1000000007;


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

/*
const int N = 1200000;

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

vector<int> B, N;

int n;

pair<int, int> check(int d)
{
    int maxB = 1e9;
    int minB = 0;
    int maxN = 1e9;
    int minN = 0;

    int maxBminusN = 1e9;
    int minBminusN = -1e9;

    for (int i = 0; i<n; i++)
    {
        maxB = min(maxB, B[i] + d);
        minB = max(minB, B[i]-d);
        maxN = min(maxN, N[i] + d);
        minN = max(minN, N[i]-d);
        maxBminusN = min(maxBminusN , B[i]-N[i] + d);
        minBminusN = max(minBminusN, B[i]- N[i]-d);
    }

    //cout<<maxB<<' '<<minB<<' '<<maxN<<' '<<minN<<' '<<maxBminusN<<' '<<minBminusN<<endl;

    if (maxB<minB || maxN<minN || maxBminusN<minBminusN) return mp(-1, -1);

    for (int B1 = minB; B1<=maxB; B1++) if (minBminusN <= B1 - maxN && B1 - maxN <=maxBminusN && B1 + maxN>0) return mp(B1, maxN);
    for (int N1 = minN; N1<=maxN; N1++) if (minBminusN <= maxB - N1 && maxB - N1 <=maxBminusN && N1 + maxB>0) return mp(maxB, N1);
    return mp(-1, -1);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;

    vector<string> s(n);
    for (int i = 0; i<n; i++)
    {
        cin>>s[i];
    }

    B.resize(n); N.resize(n);
    for (int i = 0; i<n; i++)
    {
        for (auto c: s[i]) if (c=='B') B[i]++; else N[i]++;
    }

    //for (int i = 0; i<n; i++) cout<<B[i]<<' '<<N[i]<<endl;


    //check(12);

    int L = 0;
    int R = 1e6;
    auto pr = check(L);
    if (pr.first!=-1)
    {
        cout<<L<<endl;
        for (int i = 0; i<pr.first; i++) cout<<'B';
        for (int i = 0; i<pr.second; i++) cout<<'N';
        return 0;
    }

    while (R-L>1)
    {
        int mid = (L+R)/2;
        pr = check(mid);
        if (pr.first==-1) L = mid; else R = mid;
    }

    pr = check(R);
    cout<<R<<endl;
    for (int i = 0; i<pr.first; i++) cout<<'B';
    for (int i = 0; i<pr.second; i++) cout<<'N';

}