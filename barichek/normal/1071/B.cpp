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

string s[arr];
int max_a[ar][ar];

int suf_class[ar][ar];

vector<pii> vec[arr];
int n,k;

int get(pii a)
{
    int res=1e9;
    if (a.fir!=n){
        res=min(res,suf_class[a.fir+1][a.sec]);
    }
    if (a.sec!=n){
        res=min(res,suf_class[a.fir][a.sec+1]);
    }
    return res;
}

bool cmp(pii a,pii b)
{
    return get(a)<get(b);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>k;
//    n=2000;
//    k=0;
    for (int i=0;i<n;i++){
        cin>>s[i];
//        s[i].assign(n,'a');
//        for (auto& j:s[i]){
//            j=rand()%26+'a';
//        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            max_a[i][j]=(s[i-1][j-1]=='a')+max(max_a[i-1][j],max_a[i][j-1]);
        }
    }
    if (max_a[n][n]+k>=2*n-1){
        cout<<string(2*n-1,'a')<<"\n";
        return 0;
    }

    suf_class[n][n]=0;
    for (int sum=2*n-1;sum>=2;sum--){
//        cerr<<"sum :: "<<sum<<"\n";
        for (int l='a';l<='z';l++){
            vec[l].clear();
        }
        for (int i=1;i<=sum-1;i++){
            int j=sum-i;
            if (min(i,j)>=1&&max(i,j)<=n){
                vec[s[i-1][j-1]].pb(mp(i,j));
            }
        }
        int last=0;
        for (int l='a';l<='z';l++){
//            cerr<<" l :: "<<l<<"\n";
//            cerr<<"  "<<len(vec[l])<<"\n";
            sort(all(vec[l]),cmp);
//            cerr<<" l :: "<<l<<"\n";
            for (int i=0;i<len(vec[l]);i++){
                if (i==0){
                    suf_class[vec[l][i].fir][vec[l][i].sec]=last++;
                }
                else{
                    if (get(vec[l][i])==get(vec[l][i-1])){
                        suf_class[vec[l][i].fir][vec[l][i].sec]=suf_class[vec[l][i-1].fir][vec[l][i-1].sec];
                    }
                    else{
                        suf_class[vec[l][i].fir][vec[l][i].sec]=last++;
                    }
                }
            }
        }
    }

    pair<pii,pii> ans;
    ans=mp(mp(-md,-md),mp(-1,-1));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            pair<pii,pii> cur=mp(mp(-2,-2),mp(i,j));

            int kek1=max_a[i][j]-(s[i-1][j-1]=='a');
            int kek2=(i-1)+(j-1)-kek1;

            cur.fir.fir=kek1+min(k,kek2);

            if (cur.fir.fir!=(i-1)+(j-1)){
                continue;
            }

            cur.fir.sec=-suf_class[i][j];

            ans=max(ans,cur);
        }
    }

//    cout<<ans.fir.fir<<" "<<ans.fir.sec<<" "<<ans.sec.fir<<" "<<ans.sec.sec<<"\n";

    string res="";
    res+=string(ans.fir.fir,'a');
    int x=ans.sec.fir;
    int y=ans.sec.sec;
    while (x<=n&&y<=n){
        res+=s[x-1][y-1];
        if (x==n){
            y++;
        }
        elif (y==n){
            x++;
        }
        else{
            if (suf_class[x+1][y]<suf_class[x][y+1]){
                x++;
            }
            else{
                y++;
            }
        }
    }
    cout<<res<<"\n";
}