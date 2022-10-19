#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct BIT
{
    vector<long long> data;
    int sz;
    void init(int cnt)
    {
        int n = 2;
        while (n < cnt)
            n <<= 1;
        sz = n;
        data.resize(n + 1, 0ll);
    }
    long long operator[](int where)
    {
        long long res = 0;
        while (where > 0)
        {
            res += data[where];
            where -= where & -where;
        }
        return res;
    }
    void add(int where, long long value)
    {
        while (where <= sz)
        {
            data[where] += value;
            where += where & -where;
        }
    }
};
int a[200005], b[200005];
ll dev[200005], devjie[200005], jie[200005];
int num[200005];
ll mod = 998244353;
int main(void)
{
    //ios::sync_with_stdio(false);
    jie[0] = devjie[0] = dev[1] = 1;
    for (int i = 2; i < 200005;i++)
        dev[i] = (mod - mod / i) * dev[mod % i] % mod;
    for (int i = 1; i < 200005;i++)
    {
        jie[i] = jie[i - 1] * i % mod;
        devjie[i] = devjie[i - 1] * dev[i] % mod;
    }//cout<<dev[12]*12%mod<<endl;
    int n, m;
    cin >> n >> m;
    BIT bit;
    bit.init(200005);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d",a+i);
        num[a[i]]++;
    }

    for (int i = 1; i <= m; i++)
        scanf("%d", b + i);
    b[++m] = 0;
    ll ans = 1, sum = 0;
    ans = jie[n];
    for (int i = 1; i < 200005;i++)
        ans = ans * devjie[num[i]] % mod;
    for (int i = 1; i <= n;i++)
        bit.add(a[i]+1,1);
    for (int i = 1; i <= n; i++)
    {
        ans = ans * dev[n - i + 1] % mod;//cout<<"<<<<<"<<i<<" "<<ans<<endl;
        ll k=0;
        if (b[i] > 0)
            k=bit[b[i]];//cout<<"<<"<<i<<" "<<k<<endl;
        sum += ans * k % mod;//cout<<"<<"<<i<<" "<<sum<<endl;
        if (num[b[i]] == 0)
            break;
        ans = ans * num[b[i]] % mod;
        
        num[b[i]]--;
        bit.add(b[i]+1, -1);
        if(i==n&&m>n+1)sum++;
    }
    cout << sum % mod << endl;
    return 0;
}