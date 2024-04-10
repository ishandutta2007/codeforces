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

int n;
string s;
int x,y;
string t;

int cnt[arr][4];

int get(int l,int r,int id)
{
    if (l>r){
        return 0;
    }
    return cnt[r][id]-(l==0?0:cnt[l-1][id]);
}

bool check(int X)
{
//    cout<<"check :: "<<X<<"\n";
    if (X==0){
        int xx=0,yy=0;
        for (auto i:s){
            if (i=='U'){
                yy++;
            }
            if (i=='D'){
                yy--;
            }
            if (i=='L'){
                xx--;
            }
            if (i=='R'){
                xx++;
            }
        }
        if (xx==x&&yy==y){
            return 1;
        }
        else{
            return 0;
        }
    }

    for (int i=0;i+X-1<n;i++){
        int L=i,R=i+X-1;

        int xx=0,yy=0;
        yy+=get(0,L-1,0);
        yy-=get(0,L-1,1);
        xx-=get(0,L-1,2);
        xx+=get(0,L-1,3);

        yy+=get(R+1,n-1,0);
        yy-=get(R+1,n-1,1);
        xx-=get(R+1,n-1,2);
        xx+=get(R+1,n-1,3);

        int LEN=R-L+1;

//        cout<<L<<" "<<R<<" :: "<<xx<<" "<<yy<<" || "<<abs(xx-x)+abs(yy-y)<<" "<<LEN<<"\n";

        if (abs(xx-x)+abs(yy-y)<=LEN&&(abs(xx-x)+abs(yy-y))%2==LEN%2){
            return 1;
        }
    }

    return 0;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    t="UDLR";

    cin>>n>>s;
    for (int i=0;i<n;i++){
        for (int j=0;j<4;j++){
            cnt[i][j]=(i==0?0:cnt[i-1][j])+(s[i]==t[j]);
        }
    }
    cin>>x>>y;

    if (!check(n)){
        cout<<-1<<"\n";
        return 0;
    }

    int l=0,r=n;
    while (r-l>0){
        int m=(l+r)/2;
        if (check(m)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<l<<"\n";
}