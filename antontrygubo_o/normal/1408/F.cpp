#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define mp make_pair

int p = 1000000007;




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
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

vector<pair<int, int>> ops;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    if (n<=2) {cout<<0; return 0;}
    int deg = 1;
    while ((1<<(deg+1))<=n) deg++;
    for (int i = 0; i<deg; i++)
    {
        int N = (1<<i);
        for (int j = 0; j<(1<<deg); j++)
        {
            if (j&N) ops.push_back(mp(j^N, j));
        }
    }

    int leftover = n - (1<<deg);

    cout<<ops.size()*2<<endl;
    for (auto it: ops) cout<<it.first + leftover + 1 <<' '<<it.second + leftover + 1<<endl;
    for (auto it: ops) cout<<it.first + 1 <<' '<<it.second + 1<<endl;



}
/*
1
 5 3
1 2 3 4 5
 */