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

const int n=666;
int x[arr];
int y[arr];
int xx,yy;

int cnt_x[arr];
int cnt_y[arr];

bool check(int X,int Y)
{
    for (int i=1;i<=n;i++){
        if (x[i]==X&&y[i]==Y){
            return 1;
        }
    }
    return 0;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>xx>>yy;
    for (int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    while (xx!=500||yy!=500){
        if (xx>500){
            cout<<(--xx)<<" "<<yy<<"\n";
        }
        elif (xx<500){
            cout<<(++xx)<<" "<<yy<<"\n";
        }
        elif (yy>500){
            cout<<xx<<" "<<(--yy)<<"\n";
        }
        elif (yy<500){
            cout<<xx<<" "<<(++yy)<<"\n";
        }

        int id,xxx,yyy;
        cin>>id>>xxx>>yyy;
        if (id==-1){
            return 0;
        }
        x[id]=xxx;
        y[id]=yyy;
    }
    for (int i=1;i<=n;i++){
        cnt_x[x[i]]++;
        cnt_y[y[i]]++;
    }
    int cnt1=0; /// up
    int cnt2=0; /// down
    int cnt3=0; /// left
    int cnt4=0; /// right
    int cnt13=0;
    int cnt23=0;
    int cnt14=0;
    int cnt24=0;
    for (int i=1;i<=n;i++){
        if (x[i]<500||y[i]<500){
            cnt13++;
        }
    }
    for (int i=1;i<=n;i++){
        if (x[i]>500||y[i]<500){
            cnt23++;
        }
    }
    for (int i=1;i<=n;i++){
        if (x[i]<500||y[i]>500){
            cnt14++;
        }
    }
    for (int i=1;i<=n;i++){
        if (x[i]>500||y[i]>500){
            cnt24++;
        }
    }
    int opt=max({cnt13,cnt23,cnt24,cnt14});
    if (cnt13==opt){
        for (int i=499,j=499;i>=1;i--,j--){
            if (check(i,j)){
                cout<<i<<" "<<j+1<<"\n";
                return 0;
            }
            cout<<i<<" "<<j<<"\n";
            int id,xxx,yyy;
            cin>>id>>xxx>>yyy;
            if (id==-1){
                return 0;
            }
            if (id==0){
                return 0;
            }
            x[id]=xxx;
            y[id]=yyy;
        }
        assert(0);
    }
    if (cnt23==opt){
        for (int i=501,j=499;i<=999;i++,j--){
            if (check(i,j)){
                cout<<i<<" "<<j+1<<"\n";
                return 0;
            }
            cout<<i<<" "<<j<<"\n";
            int id,xxx,yyy;
            cin>>id>>xxx>>yyy;
            if (id==-1){
                return 0;
            }
            if (id==0){
                return 0;
            }
            x[id]=xxx;
            y[id]=yyy;
        }
        assert(0);
    }
    if (cnt24==opt){
        for (int i=501,j=501;j<=999;i++,j++){
            if (check(i,j)){
                cout<<i<<" "<<j-1<<"\n";
                return 0;
            }
            cout<<i<<" "<<j<<"\n";
            int id,xxx,yyy;
            cin>>id>>xxx>>yyy;
            if (id==-1){
                return 0;
            }
            if (id==0){
                return 0;
            }
            x[id]=xxx;
            y[id]=yyy;
        }
        assert(0);
    }
    if (cnt14==opt){
        for (int i=499,j=501;i>=1;i--,j++){
            if (check(i,j)){
                cout<<i<<" "<<j-1<<"\n";
                return 0;
            }
            cout<<i<<" "<<j<<"\n";
            int id,xxx,yyy;
            cin>>id>>xxx>>yyy;
            if (id==-1){
                return 0;
            }
            if (id==0){
                return 0;
            }
            x[id]=xxx;
            y[id]=yyy;
        }
        assert(0);
    }
    assert(0);
}