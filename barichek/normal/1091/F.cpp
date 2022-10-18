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

int l[arr];

int get()
{
    int cnt_L=0;
    for (auto i:s){
        cnt_L+=(i=='L');
    }
    int ans=0;
    int have_3=0;
    int have_5=0;
    int k1=0;
    int k2=0;
    int kek_barika=0;
    for (int i=0;i<n;i++){
        cnt_L-=(s[i]=='L');
        if (s[i]=='G'){
            have_5=1;
            int cur=l[i];

//            while (cur>0&&k1){
//                k1--;
//                ans+=2;
//                cur--;
//            }
            int lol=min(cur,k1);
            k1-=lol;
            ans+=lol*2;
            cur-=lol;

            kek_barika+=lol;

            ans+=cur*3;
            k2+=cur;
        }
        elif (s[i]=='W'){
            have_3=1;
            ans+=l[i]*2;
            k1+=l[i];
        }
        else{
            int cur=l[i];

//            while (cur>0&&k1){
//                cur--;
//                k1--;
//                ans+=1;
//            }
            int lol1=min(cur,k1);
            cur-=lol1;
            k1-=lol1;
            ans+=lol1;

            int pisun;

            if (cur!=0){

                pisun=min(cur,kek_barika);

                k1+=pisun;
                k2+=pisun;
                ans+=pisun;
                kek_barika-=pisun;

                int lol1=min(cur,k1);
                cur-=lol1;
                k1-=lol1;
                ans+=lol1;
            }

//            while (cur>0&&k2){
//                cur--;
//                k2--;
//                ans+=2;
//            }
            int lol2=min(cur,k2);
            cur-=lol2;
            k2-=lol2;
            ans+=lol2*2;

            if (have_3){
                ans+=cur*3;
            }
            elif (have_5){
                ans+=cur*5;
            }
            else{
                assert(0);
            }

            ans+=l[i];
        }
    }
    return ans;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n;
    for (int i=0;i<n;i++){
        cin>>l[i];
    }
    cin>>s;
    int ans=get();
    cout<<ans<<"\n";
}