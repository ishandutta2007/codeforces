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

int cnt[100];

void solve()
{
    string s;
    cin>>s;
    if (len(s)%2==1){
        cout<<string(len(s)-1,'9')<<"\n";
        return;
    }
    memset(cnt,0,sizeof(cnt));
    for (auto i:s){
        cnt[i-'0']^=1;
    }
    for (int i=len(s)-1;i>=0;i--){
        cnt[s[i]-'0']^=1;
        /// if equal prefixes [0;i)
        for (int cur_val=s[i]-1;cur_val>='0'+(i==0);cur_val--){
            cnt[cur_val-'0']^=1;

            int cnt_non_zero=0;
            for (int j=0;j<10;j++){
                if (cnt[j]){
                    cnt_non_zero++;
                }
            }
            if (cnt_non_zero<=(len(s)-i)){
                string t=s.substr(0,i);
                t+=char(cur_val);
                string tt="";
                for (int j=0;j<10;j++){
                    if (cnt[j]){
                        tt+=char(j+'0');
//                        cout<<char(j+'0')<<" !!!\n";
                    }
                }
                while (len(tt)+len(t)<len(s)){
                    tt+="99";
                }
                sort(all(tt));
                reverse(all(tt));
//                cout<<t<<" :: "<<tt<<"\n";
                cout<<t<<tt<<"\n";
                return;
            }

            cnt[cur_val-'0']^=1;
        }
    }
    int kek=len(s)-1;
    if (kek%2==1){
        kek--;
    }
//    cout<<"kek :: "<<kek<<"\n";
    cout<<string(kek,'9')<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}