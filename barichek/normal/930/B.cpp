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

#define ar (int)(5000+10)

vector<string> ss[26];
int cnt[26][ar][26];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    for (int i=0;i<len(s);i++){
        string t=s.substr(i)+s.substr(0,i);
        ss[t.front()-'a'].pb(t);
        for (int j=0;j<len(s);j++){
            cnt[t.front()-'a'][j][t[j]-'a']++;
        }
    }
    ld ans=0;
    for (char c='a';c<='z';c++){
        if (!ss[c-'a'].empty()){
//            cout<<c<<"\n";
            ld cur_res=0;
            ld cur_kf=ld(len(ss[c-'a']))/ld(len(s));
            for (int i=0;i<len(s);i++){
                ld cur_cur=0;
                for (int res='a';res<='z';res++){
                    ld cur_kf_kf=ld(cnt[c-'a'][i][res-'a'])/ld(len(ss[c-'a']));
                    if (cnt[c-'a'][i][res-'a']==1){
//                        cout<<cur_kf<<" "<<cur_kf_kf<<"\n";
                        cur_cur+=cur_kf*cur_kf_kf;
                    }
                }
//                cout<<"cur_cur :: "<<cur_cur<<"\n";
                cur_res=max(cur_res,cur_cur);
            }
            ans+=cur_res;
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<"\n";
}