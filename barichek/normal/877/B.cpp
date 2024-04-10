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

///---program start---///

int cnt1[arr];
int cnt2[arr];

int get1(int l,int r)
{
    if (l>r){
        return 0;
    }
    return cnt1[r]-(l==0?0:cnt1[l-1]);
}

int get2(int l,int r)
{
    if (l>r){
        return 0;
    }
    return cnt2[r]-(l==0?0:cnt2[l-1]);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    for (int i=0;i<len(s);i++){
        if (i){
            cnt1[i]+=cnt1[i-1];
        }
        cnt1[i]+=(s[i]=='a');
    }
    for (int i=0;i<len(s);i++){
        if (i){
            cnt2[i]+=cnt2[i-1];
        }
        cnt2[i]+=(s[i]=='b');
    }
    int ans=0;
    for (int i=0;i<=len(s);i++){
        for (int j=i;j<=len(s);j++){
            int cur_ans=0;
            cur_ans+=get1(0,i-1);
            cur_ans+=get2(i,j-1);
            cur_ans+=get1(j,len(s)-1);
            ans=max(ans,cur_ans);
        }
    }
    cout<<ans<<"\n";
}