#pragma GCC optimize("O3")
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

#define oryshych_jebosh main

///---program start---///

int a[ar][ar];

oryshych_jebosh()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int ans1=0;
    int ans2=0;
    for (int j=1;j<=m;j++){
        int kek=0;
        int cur_ans1=0;
        int cur_ans2=0;
        for (int i=1;i<=n;i++){
            if (a[i][j]==1){
                int lal=0;
                for (int i1=i;i1<=n&&i1<=i+k-1;i1++){
                    lal+=a[i1][j];
                }
                if (lal>cur_ans1){
                    cur_ans1=lal;
                    cur_ans2=kek;
                }
                kek++;
            }
        }
        ans1+=cur_ans1;
        ans2+=cur_ans2;
    }
    cout<<ans1<<" "<<ans2<<"\n";
}