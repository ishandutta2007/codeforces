#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

//int gcd (int a, int b, int & x, int & y) {
//	if (a == 0) {
//		x = 0; y = 1;
//		return b;
//	}
//	int x1, y1;
//	int d = gcd (b%a, a, x1, y1);
//	x = y1 - (b / a) * x1;
//	y = x1;
//	return d;
//}
//
//bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
////    cerr<<"a b c :: "<<a<<" "<<b<<" "<<c<<"\n";
//	g = gcd (abs(a), abs(b), x0, y0);
////	cerr<<"gavno g :: "<<g<<"\n";
//	if (c % g != 0)
//		return false;
//	x0 *= c / g;
//	y0 *= c / g;
//	if (a < 0)   x0 *= -1;
//	if (b < 0)   y0 *= -1;
//
////    cerr<<a*x0+b*y0<<" "<<c<<"\n";
//	return true;
//}

int cnt;
vi easy;

int f1(int a,int b)
{
//    cerr<<"f1("<<a<<","<<b<<")\n";
    if (b==0){
        return 0;
    }
//    cerr<<"g :: "<<__gcd(a,b)<<"\n";
    return 1+f1(a,b-__gcd(a,b));
}

int f(int a,int b)
{
//    assert(++cnt<=50);
//    cerr<<"f("<<a<<","<<b<<")\n";
    int g=__gcd(a,b);
//    cerr<<"g :: "<<g<<"\n";
    if (b==0){
        return 0;
    }
    int val=1e15;
//    if (b%g==0){
//        val=b/g;
//    }
    int k1=a/g;
    if (k1==1){
        return b/g;
    }
    int k2=b/g;
//    cerr<<"k1 :: "<<k1<<"\n";
//    cerr<<"k2 :: "<<k2<<"\n";
    /// k2-l*g had with k1x
    easy.clear();
    int aa=k1;
    for (int i=1;i*i<=aa;i++){
        if (aa%i==0){
            if (i!=1){
                easy.pb(i);
            }
            easy.pb(aa/i);
        }
    }
    for (auto i:easy){
//        cerr<<"i :: "<<i<<"\n";
//        int cur=1e9;
        int x_kek,y_kek,kekkek;
//        if (!find_any_solution(i,g,k2,x_kek,y_kek,kekkek)){
//            cerr<<"this is kek"<<"\n";
//            continue;
//        }
//        cerr<<"x_kek :: "<<x_kek<<"\n";
//        cerr<<"y_kek :: "<<y_kek<<"\n";
//        int ag=i/kekkek;
//        y_kek%=ag;
//        if (y_kek<0){
//            y_kek+=ag;
//        }
        y_kek=k2%i;
//        cerr<<"y_kek :: "<<y_kek<<"\n";
        if (y_kek==0){
            y_kek=i;
        }
//        cerr<<"kakaha :: "<<(k2-y_kek)%i<<"\n";
//        cerr<<"kek :: "<<__gcd(a,b-y_kek*g)<<"\n";
//        cerr<<"kek2 :: "<<__gcd(k1,k2-y_kek)<<"\n";
        val=min(val,y_kek);
    }
//    cerr<<"val :: "<<val<<"\n";
//    cerr<<b-val*g<<" "<<__gcd(a,b-val*g)<<" !!!\n";
    assert(k1==1||b-val*g==0||__gcd(a,b-val*g)>g);
    return val==1e15?b:val+f(a,b-val*g);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int a,b;
    cin>>a>>b;
    cout<<f(a,b)<<"\n";
//    cout<<f1(a,b)<<"\n";
}