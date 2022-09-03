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

set<int> good, bad;
set<int> largest, smallest;

ll sum_largest = 0;
ll sum_total = 0;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for (int i = 0; i<n; i++)
    {
        int tp, d;
        cin>>tp>>d;
        sum_total+=d;

        if (tp==0)
        {
            if (d>0)
            {
                bad.insert(d);
                if (largest.size()>0 && *largest.begin()<d)
                {
                    largest.insert(d); sum_largest+=d;
                }
                else smallest.insert(d);
            }
            else
            {
                d*=-1;
                bad.erase(d);
                if (smallest.count(d)) smallest.erase(d);
                else {largest.erase(d); sum_largest-=d;}
            }
        }
        else
        {
            if (d>0)
            {
                good.insert(d);
                if (largest.size()>0 && *largest.begin()<d)
                {
                    largest.insert(d); sum_largest+=d;
                }
                else smallest.insert(d);
            }
            else
            {
                d*=-1;
                good.erase(d);
                if (smallest.count(d)) smallest.erase(d);
                else {largest.erase(d); sum_largest-=d;}
            }
        }

        if (largest.size()<good.size())
        {
            int x = *prev(smallest.end());
            smallest.erase(x);
            largest.insert(x);
            sum_largest+=x;
        }

        if (largest.size()>good.size())
        {
            int x = *largest.begin();
            largest.erase(x);
            smallest.insert(x);
            sum_largest-=x;
        }

        if (good.size()==0)
        {
            cout<<sum_total<<endl;
            continue;
        }
        else
        {
            if (*largest.begin()!=*good.begin()) cout<<sum_total+sum_largest<<endl;
            else
            {
                ll tmp = sum_total + sum_largest;
                tmp-=*good.begin();
                if (bad.size()>0) tmp+=*prev(bad.end());
                cout<<tmp<<endl;
            }
        }

    }

}