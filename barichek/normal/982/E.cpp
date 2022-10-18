#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int n,m,x,y,vx,vy;

void print_no()
{
    cout<<-1<<"\n";
    exit(0);
}

void print_ans(int x,int y)
{
//    cout<<"print_ans :: "<<x<<" "<<y<<"\n";
    int xx=-1;
    int yy=-1;
    if (abs(x/n)%2==0){
        xx=0;
    }
    else{
        xx=n;
    }
    if (abs(y/m)%2==0){
        yy=0;
    }
    else{
        yy=m;
    }
    cout<<xx<<" "<<yy<<"\n";
    exit(0);
}

int my_gcd(int a,int b,int& x0,int& y0)
{
    if (a==0){
        x0=0;
        y0=1;
        return b;
    }
    int x,y;
    int g=my_gcd(b%a,a,x,y);
    x0=y-(b/a)*x;
    y0=x;
    return g;
}

int find_solution(int x0,int y0,int a,int b)
{
//    cout<<"x0 y0 a b :: "<<x0<<" "<<y0<<" || "<<a<<" "<<b<<"\n";
    /// x=x0+k*b
    /// y=y0-k*a
    /// x>=0 y>=0
    /// x -> min

    int l=-1e10,r=1e10;
    while (r-l>3){
        int m=(l+r)/2;
        if (x0+m*b<0||y0-m*a<0){
            r=m;
        }
        else{
            l=m;
        }
    }

    for (int i=r;i>=l;i--){
//        cout<<i<<" :: "<<x0+i*b<<" "<<y0-i*a<<"\n";
        if (x0+i*b>=0&&y0-i*a>=0){
            return x0+i*b;
        }
    }
    assert(0);
}

int find_solution(int A,int B,int C)
{
//    cout<<"Evklid :: "<<A<<" "<<B<<" "<<C<<"\n";
    int x0,y0;
    int g=my_gcd(abs(A),abs(B),x0,y0);
//    cout<<"start x0 y0 :: "<<x0<<" "<<y0<<"\n";
    if (C%g!=0){
        return -1;
    }
    x0*=C/g;
    y0*=C/g;
    if (A<0){
        x0*=-1;
    }
    if (B<0){
        y0*=-1;
    }
//    cout<<"x0 y0 :: "<<x0<<" "<<y0<<"\n";
    /// x=x0+k*(b/g)
    /// y=y0-k*(a/g)
    return find_solution(x0,y0,A/g,B/g);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n>>m>>x>>y>>vx>>vy;
    if (vx==0){
        if (x%n==0){
            if (vy==-1){
                print_ans(x,0);
            }
            else{
                print_ans(x,m);
            }
        }
        else{
            print_no();
        }
    }
    if (vy==0){
        if (y%m==0){
            if (vx==-1){
                print_ans(0,y);
            }
            else{
                print_ans(n,y);
            }
        }
        else{
            print_no();
        }
    }
    int t_mod_n=((-vx*x)%n+n)%n;
    int t_mod_m=((-vy*y)%m+m)%m;

//    cout<<"mods :: "<<t_mod_n<<" "<<t_mod_m<<"\n";

    int res=find_solution(n,-m,-(t_mod_n-t_mod_m));

//    cout<<"res :: "<<res<<"\n";

    if (res==-1){
        print_no();
    }

    int t=res*n+t_mod_n;
//    cout<<"t :: "<<t<<"\n";

    print_ans(x+t*vx,y+t*vy);
}