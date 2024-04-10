#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=683;
    vector<bool> sieve(N+1,1);
    vector<int> primes;
    for(int i=2;i<=N;i++)
    {
        if(sieve[i]==0) continue;
        primes.push_back(i);
        for(int j=i*i;j<=N;j+=i) sieve[j]=0;
    }
    int sz=primes.size();
    const ll small=1000000000;
    const ll lim=1000000000000000000;
    int t;
    cin >> t;
    while(t--)
    {
        auto q=[&](ll a)->ll
        {
            cout << "? " << a << "\n";
            cout.flush();
            ll g;
            cin >> g;
            return g;
        };
        ll r=1;
        for(int i=0;i<4;i+=2)
        {
            ll a=1;
            for(int j=i;j<=i+1;j++)
            {
                ll b=1;
                while(b*primes[j]<=small) b*=primes[j];
                a*=b;
            }
            r*=q(a);
        }
        int idx=4;
        while(idx<sz)
        {
            ll p=1;
            while(idx<sz&&p<=lim/primes[idx]) p*=primes[idx++];
            r*=q(p);
        }
        for(int i=0;i<3;i++) r=q(r*r);
        ll d=1;
        for(ll p:primes)
        {
            int c=0;
            while((r%p)==0)
            {
                c++;
                r/=p;
            }
            d*=(c+1);
        }
        if(d<=2) cout << "! " << d+7 << "\n";
        else cout << "! " << 2*d << "\n";
        cout.flush();
    }
    return 0;
}