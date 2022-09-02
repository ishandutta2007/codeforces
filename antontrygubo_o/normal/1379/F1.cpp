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
{*
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

int n, m, q;
vector<pair<int, int>> cell;

bool check(int k)
{
    vector<int> a(2*m);
    for (int i = 0; i<2*m; i+=2) a[i] = n-1;
    for (int i = 1; i<2*m; i+=2) a[i] = 0;
    for (int i = 0; i<k; i++)
    {
        auto c = cell[i];
        if (c.second%2 == 0) a[c.second] = min(a[c.second], c.first/2 - 1);
        else a[c.second] = max(a[c.second], c.first/2 + 1);
    }

    int cur = n-1;
    for (int i = 0; i<m; i++)
    {
        cur = min(cur, a[2*i]);
        if (a[2*i+1]>cur+1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>m>>q;

    cell.resize(q);
    for (int i = 0; i<q; i++)
    {
        cin>>cell[i].first>>cell[i].second;
        cell[i].first--; cell[i].second--;
    }

    int L = 0;
    int R = q;
    if (check(R))
    {
        for (int i = 0; i<q; i++) cout<<"YES"<<endl;
        return 0;
    }
    while (R-L>1)
    {
        int mid = (L+R)/2;
        if (check(mid)) L = mid; else R = mid;
    }
    for (int i = 0; i<L; i++) cout<<"YES"<<endl;
    for (int i = R-1; i<q; i++) cout<<"NO"<<endl;







}