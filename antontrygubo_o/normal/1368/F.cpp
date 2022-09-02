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


const int p = 1e9 + 7;


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

int remove(vector<int> &a)
{
    cout<<a.size()<<' ';
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
    int x;
    cin>>x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;

    if (n<=3)
    {
        cout<<0<<endl;
        return 0;
    }

    int res = 0;
    int best = 0;
    for (int i = 2; i<=n-1; i++)
    {
        int tmp = n - (n+i-1)/i - (i-1);
        if (tmp>res)
        {
            res = tmp;
            best = i;
        }
    }

    set<int> good;
    for (int i = 1; i<=n; i++) if (i%best!=0) good.insert(i);
    if (n%best!=0)
    {
        good.erase(n);
    }

    set<int> to_do(good);

    set<int> on;

    while (on.size()<res)
    {
        vector<int> erasing;
        for (int i = 0; i<best; i++)
        {
            erasing.push_back(*to_do.begin());
            on.insert(*to_do.begin());
            to_do.erase(to_do.begin());
        }
        int off = remove(erasing);
        for (int i = 0; i<best; i++)
        {
            int lamp = (off-1 + i)%n + 1;
            if (on.count(lamp))
            {
                on.erase(lamp);
                to_do.insert(lamp);
            }
        }
    }

    cout<<0; return 0;
}