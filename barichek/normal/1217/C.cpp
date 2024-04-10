//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

int cnt_zeroes_left[arr];

int get(int pos)
{
    return pos<0?0:cnt_zeroes_left[pos];
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int test;
    cin>>test;
    while (test--){
        string s;
        cin>>s;
        for (int i=0;i<len(s);i++){
            cnt_zeroes_left[i]=(s[i]=='0'?1+(i==0?0:cnt_zeroes_left[i-1]):0);
        }
        int ans=0;
        for (int i=0;i<len(s);i++){
            int cur=0;
            int pw=1;
            for (int j=i;j>=0&&i-j+1<=20;j--){
                if (s[j]=='1'){
                    cur+=pw;
                }
                pw*=2;
                if (s[j]=='1'&&cur>=i-j+1){
                    if (get(j-1)>=cur-(i-j+1)){
//                        cout<<s.substr(j,i-j+1)<<" !!!\n";
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}