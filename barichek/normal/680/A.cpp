#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define clear_screen fflush(stdout);
#define endl putchar('\n')
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;
typedef long double ld;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const ll md=1e9+7;
const ld eps=1e-6;

///---math_fun---///

template<typename type> inline type sqr(type n)
{
    return n*n;
}

template<typename type> inline type pow(type a,type n)
{
    if (n==0) return 1;
    if (n==1) return a;
    if (n%2) return a*pow(a,n-1);
    else return sqr(pow(a,n/2));
}

template<typename type1,typename type2> inline ll __gcd(type1 a,type2 b)
{
    while (a&&b)
        (a>b)?a%=b:b%=a;
    return a+b;
}

///---read---///

inline bool read(char &n)
{
    n=' ';
    while (true)
    {
        n=getchar();
        if (feof(stdin)) break;
        if (n==' '||n=='\n') continue;
        return true;
    }
    return false;
}

inline bool read(string &n)
{
    char c;
    n="";
    bool work=false;
    while (true)
    {
        c=getchar();
        if (feof(stdin)) break;
        if (c==' '||c=='\n')
        {
            if (work) break;
            else continue;
        }
        n+=c;
        work=true;
    }
    if (work) return true;
    else return false;
}

template<typename type> inline bool read(type &n)
{
    if (typeid(ld)==typeid(n)||typeid(double)==typeid(n))
    {
        n=(type)0;
        int st=1;
        char c;
        bool minus=false;
        bool left=true;
        bool work=false;
        type step[20];
        step[1]=1e-1;
        for (int i=2;i<20;i++)
            step[i]=step[i-1]/10;
        while (true)
        {
            c=getchar();
            if (feof(stdin)) break;
            if (c==' '||c=='\n')
            {
                if (work) break;
                else continue;
            }
            if (c=='-') minus=true;
            elif (c=='.') left=false;
            elif (left) n=n*10+c-'0', work=true;
            else n+=(c-'0')*step[st++], work=true;
        }
        if (minus) n*=(type)-1;
        if (work) return true;
        else return false;
    }
    else
    {
        n=0;
        char c;
        bool minus=false;
        bool work=false;
        while (true)
        {
            c=getchar();
            if (feof(stdin)) break;
            if (c==' '||c=='\n')
            {
                if (work) break;
                else continue;
            }
            if (c=='-') minus=true;
            else n=n*10+c-'0', work=true;
        }
        if (minus) n*=-1;
        if (work) return true;
        else return false;
    }
}

template<typename type1,typename type2> inline bool read(type1 &a,type2 &b)
{
    return read(a)&&read(b);
}

///---write---///

inline void write_(char n)
{
    putchar(n);
}

inline void write_(string n)
{
    for (int i=0;i<n.length();i++)
        putchar(n[i]);
}

template<typename type> inline void write_(type n)
{
    if (typeid(ld)==typeid(n)||typeid(double)==typeid(n))
        printf("%.8f",(double)n);
    else
    {
        if (n==0)
        {
            putchar('0');
            return;
        }
        char ans[20];
        int kil=0;
        if (n<0) putchar('-'), n*=-1;
        while (n)
        {
            ans[kil++]=char(n-(n/10)*10+'0');
            n/=10;
        }
        for (int i=kil-1;i>=0;i--)
            putchar(ans[i]);
    }
}

template<typename type> inline void write(type n)
{
    write_(n);
    putchar(' ');
}

template<typename type1,typename type2> inline void write(type1 a,type2 b)
{
    write(a);
    write(b);
}

template<typename type> inline void writeln(type n)
{
    write_(n);
    endl;
}

template<typename type1,typename type2> inline void writeln(type1 a,type2 b)
{
    write(a);
    writeln(b);
}

///---program start---///

int main()
{
    int a[5];
    for (int i=0;i<5;i++)
        read(a[i]);
    sort(a,a+5);
    int ans=0;
    for (int i=0;i<=3;i++)
        ans=max(ans,(a[i]+a[i+1])*(a[i]==a[i+1]));
    for (int i=0;i<=2;i++)
        ans=max(ans,(a[i]+a[i+1]+a[i+2])*(a[i]==a[i+1]&&a[i]==a[i+2]));
    cout<<a[0]+a[1]+a[2]+a[3]+a[4]-ans;
}