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

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;

    vector<string> a(0);

    a.pb("a1");
    a.pb("b1");
    a.pb("c1");
    a.pb("d1");
    a.pb("e1");
    a.pb("f1");
    a.pb("g1");

    a.pb("g2");
    a.pb("f2");
    a.pb("e2");
    a.pb("d2");
    a.pb("c2");
    a.pb("b2");
    a.pb("a2");

    a.pb("a3");
    a.pb("b3");
    a.pb("c3");
    a.pb("d3");
    a.pb("e3");
    a.pb("f3");
    a.pb("g3");

    a.pb("g4");
    a.pb("f4");
    a.pb("e4");
    a.pb("d4");
    a.pb("c4");
    a.pb("b4");
    a.pb("a4");

    a.pb("a5");
    a.pb("b5");
    a.pb("c5");
    a.pb("d5");
    a.pb("e5");
    a.pb("f5");
    a.pb("g5");

    a.pb("g6");
    a.pb("f6");
    a.pb("e6");
    a.pb("d6");
    a.pb("c6");
    a.pb("b6");
    a.pb("a6");

    a.pb("a7");

    a.pb("a8");
    a.pb("b8");
    a.pb("c8");
    a.pb("d8");
    a.pb("e8");
    a.pb("f8");
    a.pb("g8");

    a.pb("g7");
    a.pb("f7");
    a.pb("e7");
    a.pb("d7");
    a.pb("c7");
    a.pb("b7");

    a.pb("h7");
    a.pb("h6");
    a.pb("h5");
    a.pb("h4");
    a.pb("h3");
    a.pb("h2");
    a.pb("h1");

    n++;

    if (a[n-3][1]=='8'){
//        cout<<"mark1"<<"\n";
        if (a[n-3][0]!='g'){
            for (int i=0;i<n-2;i++){
                cout<<a[i]<<" ";
            }
            string cur=a[n-3];
            cur[0]++;
            cout<<cur<<" ";
            cur[0]='h';
            cout<<cur<<"\n";
        }
        else{
            for (int i=0;i<n-3;i++){
                cout<<a[i]<<" ";
            }
            string cur=a[n-4];
            cur[1]--;
            cout<<cur<<" ";
            cur[0]='h';
            cout<<cur<<" ";
            cur[1]='8';
            cout<<cur<<"\n";
        }
    }
    elif (a[n-3][0]=='h'){
//        cout<<"mark2"<<"\n";
        for (int i=0;i<n-1;i++){
            cout<<a[i]<<" ";
        }
        string cur=a[n-2];
        cur[1]='8';
        cout<<cur<<"\n";
    }
    else{
//        cout<<"mark3"<<"\n";
        for (int i=0;i<n-2;i++){
            cout<<a[i]<<" ";
        }
        string cur=a[n-3];
        cur[0]='h';
        cout<<cur<<" ";
        cur[1]='8';
        cout<<cur<<"\n";
    }
}