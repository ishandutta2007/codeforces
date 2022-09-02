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

void solve()
{
    int n;
    cin>>n;
    int n1 = n;
    vector<pair<int, int>> primes;
    for (int i = 2; i*i<=n1; i++) if (n1%i==0)
    {
        int cnt = 0;
        while (n1%i==0)
        {
            n1/=i; cnt++;
        }
        primes.push_back(mp(cnt, i));
    }
    if (n1>1) primes.push_back(mp(1, n1));
    sort(primes.begin(), primes.end());

    reverse(primes.begin(), primes.end());

    if (primes.size()==1)
    {
        int cur = 1;
        for (int i = 1; i<=primes[0].first; i++)
        {
            cur*=primes[0].second; cout<<cur<<' ';
        }
        cout<<endl<<0<<endl;
        return;
    }

    //for (auto it: primes) cout<<it.first<<' '<<it.second<<endl;

    if (primes[0].first>1)
    {
        p = primes[0].second;
        n1 = n;
        while (n1%p == 0) n1/=p;

        vector<int> divisors;
        for (int i = 1; i*i<=n1; i++) if (n1%i == 0)
        {
            if (i!=1) divisors.push_back(i);
            if (i*i!=n1) divisors.push_back(n1/i);
        }

        int N = divisors.size();

        for (int i = 0; i<N; i++)
        {
            cout<<divisors[i]<<' ';
            int cur = divisors[i];
            for (int j = 0; j<primes[0].first-1; j++)
            {
                cur*=p;
                cout<<cur<<' ';
            }
            if (i==0)
            {
                int cur = 1;
                for (int j = 0; j<primes[0].first; j++)
                {
                    cur*=p;
                    cout<<cur<<' ';
                }
            }
            int cur1 = divisors[(i+1)%N];
            for (int j = 0; j<primes[0].first; j++) cur1*=p;
            cout<<cur1<<' ';
        }
        cout<<endl<<0<<endl;
        return;
    }

    if (primes.size()==2)
    {
        cout<<primes[0].second<<' '<<primes[1].second<<' '<<n<<endl;
        cout<<1<<endl;
        return;
    }

    vector<int> pr;
    for (auto it: primes) pr.push_back(it.second);
    int N = pr.size();

    set<int> used;
    for (int i = 0; i<N; i++)
    {
        used.insert(pr[i]); used.insert(pr[i]*pr[(i+1)%N]);
    }

    vector<vector<int>> where(N);

    vector<int> divisors;

    for (int i = 1; i*i<=n; i++) if (n%i == 0)
    {
        if (i!=1) divisors.push_back(i);
        if (i*i!=n) divisors.push_back(n/i);
    }


    for (auto it: divisors) if (used.count(it)==0)
    {
        int cur = 0;
        while (it%pr[cur]) cur++;
        where[cur].push_back(it);
    }

    for (int i = 0; i<N; i++)
    {
        cout<<pr[i]<<' ';
        for (auto it: where[i]) cout<<it<<' ';
        cout<<pr[i]*pr[(i+1)%N]<<' ';
    }
    cout<<endl<<0<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();

}