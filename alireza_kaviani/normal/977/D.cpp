#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    fast_io;

    ll n , maxn = 0 , st = 0;
    cin >> n;
    vector<ll> a(n) , ans;
    for(int i = 0; i < n ; i++)
    {
        cin >> a[i];
        ll t = 0 ,x = a[i];
        while(x % 3 == 0)
        {
            t++;
            x /= 3;
        }
        if(t > maxn)
        {
            maxn = t;
            st = i;
        }
        if(t == maxn)
        {
            if(a[i] < a[st])
            {
                maxn = t;
                st = i;
            }
        }
    }

    ans.push_back(a[st]);

    for(int i = 0 ; i < n - 1 ; i++)
    {
        vector<ll> next;
        if(a[st] * 2 > 0)
        {
            next.push_back(a[st] * 2);
        }
        if(a[st] % 3 == 0)
        {
            next.push_back(a[st] / 3);
        }

        if(next.size() == 1)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(a[j] == next[0])
                {
                    st = j;
                    break;
                }
            }
        }

        if(next.size() == 2)
        {
            bool cont = true;
            for(int j = 0; j < n ; j++)
            {
                if(a[j] == next[0])
                {
                    st = j;
                    cont = false;
                    break;
                }
            }

            if(cont)
            {
                for(int j = 0; j < n ; j++)
                {
                    if(a[j] == next[1])
                    {
                        st = j;
                        break;
                    }
                }
            }
        }
        ans.push_back(a[st]);
    }

    for(ll i : ans)
    {
        cout << i << ends;
    }

    return 0;
}