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
///#define int long long

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

char cur[arr];
int z[arr];
int sz;

void build_z()
{
    for (int i=1,l=0,r=0;i<sz;i++){
        z[i]=0;
        if (i<=r){
            z[i]=min(z[i-l],r-i+1);
        }
        while (i+z[i]<sz&&cur[i+z[i]]==cur[z[i]]){
            z[i]++;
        }
        if (i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
}

int ans[arr];
vector<pair<string,int>> vh[arr];
int k[arr];

ll h[arr];

const int bsize=100;

const int big_base=3e5+10;

ll p[big_base];

ll get(int l,int r)
{
    ll hh=h[r]-(l==0?0:h[l-1]);
    if (hh<0){
        hh+=md;
    }

    hh*=p[big_base-l-1];
    hh%=md;

    return hh;
}

int get_hash(string s)
{
    ll res=0;
    for (int i=0;i<len(s);i++){
        res+=1ll*(s[i]-'a'+1)*p[i]%md;
        res%=md;
    }

    res*=p[big_base-1];
    res%=md;

    return res;
}

int get_ans(const vi& a,int t,int len_one)
{
//    cout<<"get_ans :: t len_one :: "<<t<<" "<<len_one<<"\n";
//    cout<<"a :: ";
//    for (auto i:a){
//        cout<<i<<" ";
//    }
//    cout<<"\n";
    if (len(a)<t){
        return -1;
    }
    int res=1e9;
    for (int i=0;i+t-1<len(a);i++){
        res=min(res,a[i+t-1]+len_one-1-a[i]+1);
    }

    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    string s;
    cin>>s;

    const int base=31;
    p[0]=1;
    for (int i=1;i<big_base;i++){
        p[i]=1ll*p[i-1]*base%md;
    }
    h[0]=s[0]-'a'+1;
    for (int i=1;i<len(s);i++){
        h[i]=(h[i-1]+1ll*(s[i]-'a'+1)*p[i])%md;
    }

    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        string t;
        cin>>k[i]>>t;
        if (len(t)>=bsize){
            for (int i=0;i<len(t);i++){
                cur[i]=t[i];
            }
            cur[len(t)]='#';
            for (int i=0;i<len(s);i++){
                cur[len(t)+i+1]=s[i];
            }
            sz=len(t)+len(s)+1;
//            cout<<"cur :: "<<cur<<"\n";
            build_z();
//            cout<<"z :: ";
//            for (int i=0;i<len(cur);i++){
//                cout<<z[i]<<" ";
//            }
//            cout<<"\n";
            vector<int> poses;
            for (int i=0;i<len(s);i++){
                if (z[i+len(t)+1]>=len(t)){
                    poses.pb(i);
                }
            }
            ans[i]=get_ans(poses,k[i],len(t));
        }
        else{
            vh[len(t)].pb({t,i});
        }
    }
    vector<int> vvv(0);
    for (int j=1;j<bsize;j++){
        vector<pii> kek(0);
        for (int i=0;i+j-1<len(s);i++){
            kek.pb({get(i,i+j-1),i});
        }
        sort(all(kek));
        for (auto q:vh[j]){
            int cur_hash=get_hash(q.fir);
            auto it=lower_bound(all(kek),mp(cur_hash,-1));
            vvv.clear();
            while (it!=kek.end()&&it->fir==cur_hash){
                vvv.pb(it->sec);
                it++;
            }
            ans[q.sec]=get_ans(vvv,k[q.sec],j);
        }
    }

    for (int i=0;i<m;i++){
        cout<<ans[i]<<"\n";
    }
}