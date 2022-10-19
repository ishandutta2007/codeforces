#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;


#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         string(1 , '\t')
#define sep                         string(1 , ' ')
#define endl                        string(1 , '\n')
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

namespace IO
{
    // input bases
    void input(int &x)      { scanf("%d" , &x);         }
    void input(ll &x)       { scanf("%I64d" , &x);      }
    void input(float &x)    { scanf("%f" , &x);         }
    void input(double &x)   { scanf("%lf" , &x);        }
    void input(char &x)     { cin >> x;                 }
    void input(string &x)   { cin >> x;                 }

    // input other
    template<class T1 , class T2>
    void input(pair<T1 , T2> &x)
    {
        input(x.X) ; input(x.Y);
    }

    template<class T1, class... T2>
    void input(T1 &x, T2&... y)
    {
        input(x) ; input(y...);
    }

    template<class T>
    void input(vector<T> &x)
    {
        for(ll i = 0 ; i < x.size() ; i++)  input(x[i]);
    }

    template<class T>
    void input(T *l , T *r)
    {
        for( ; l != r ; l++)
        {
            input(*l);
        }
    }

    // output bases
    void print(int x)       { printf("%d" , x);         }
    void print(ll x)        { printf("%I64d" , x);      }
    void print(float x)     { printf("%.10f" , x);      }
    void print(double x)    { printf("%.10f" , x);      }
    void print(char c)      { printf("%c" , c);         }
    void print(string x)    { printf("%s" , x.c_str()); }

    //output others
    template<class T1 , class T2>
    void print(pair<T1 , T2> x)
    {
        print(x.X) ; print(sep) ; print(x.Y);
    }

    template<class T1, class... T2>
    void print(T1 x, T2... y)
    {
        print(x) ; print(y...);
    }

    template<class T>
    void print(vector<T> &x)
    {
        for(ll i = 0 ; i < x.size() ; i++)  print(x[i] , sep);
    }

    template<class T>
    void print(T *l , T *r , string s = sep , string st = "" , string en = "")
    {
        print(st);
        for( ; l != r ; l++)
        {
            print(*l);
            if(l != r - 1)  print(s);
        }
        print(en);
    }
}
using namespace IO;

const ll MAXN = 5e6 + 10;
ll q , x , y , cnt[MAXN];

int main()
{
    //fast_io;

    for(ll i = 2 ; i < MAXN ; i++)
    {
        if(!cnt[i])
        {
            for(ll j = i ; j < MAXN ; j += i)
            {
                ll x = j;
                while(x % i == 0)
                {
                    cnt[j]++;
                    x /= i;
                }
            }
        }
    }
    partial_sum(cnt , cnt + MAXN , cnt);

    input(q);
    while(q--)
    {
        input(x , y);
        print(cnt[x] - cnt[y] , endl);
    }

    return 0;
}