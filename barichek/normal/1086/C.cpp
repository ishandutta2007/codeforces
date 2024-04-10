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

char what[arr];
char rwhat[arr];
int k;
string s,a,b;

void build(string& t,int m)
{
    for (int i='a';i<='a'+k-1;i++){
        what[i]=0;
        rwhat[i]=0;
    }

    t=s;
    if (m==len(s)){
        for (int i=0;i<m;i++){
            if (what[s[i]]){
                if (what[s[i]]!=a[i]){
                    return;
                }
            }
            else{
                what[s[i]]=a[i];
                rwhat[a[i]]=s[i];
            }
        }
        t=a;
        return;
    }

    for (int i=0;i<m;i++){
        t[i]=a[i];
    }

    for (int i=0;i<m;i++){
        if (what[s[i]]){
            if (what[s[i]]!=a[i]){
                return;
            }
        }
        else{
            what[s[i]]=a[i];
            rwhat[a[i]]=s[i];
        }
    }
    if (!what[s[m]]){
        for (int i=a[m]+1;i<='a'+k-1;i++){
            if (!rwhat[i]){
                what[s[m]]=i;
                rwhat[i]=s[m];
                break;
            }
        }
    }
    for (int i=m+1;i<len(s);i++){
        if (!what[s[i]]){
            for (int j='a';j<='a'+k-1;j++){
                if (!rwhat[j]){
                    what[s[i]]=j;
                    rwhat[j]=s[i];
                    break;
                }
            }
        }
    }
    for (int i=m;i<len(t);i++){
        t[i]=what[t[i]];
    }
}

multiset<char> kek1[arr];
multiset<char> kek2[arr];

void solve()
{
    cin>>k;
    cin>>s>>a>>b;
    for (int i='a';i<='a'+k-1;i++){
        kek1[i].clear();
        kek2[i].clear();
    }
    for (int i=0;i<len(s);i++){
        kek1[s[i]].insert(a[i]);
        kek2[a[i]].insert(s[i]);
    }
    int l=-1;
    for (int i=len(s)-1;i>=-1;i--){
        bool ok=1;
        for (int j='a';j<='a'+k-1;j++){
            if (!kek1[j].empty()&&*kek1[j].begin()!=*kek1[j].rbegin()){
                ok=0;
            }
            if (!kek2[j].empty()&&*kek2[j].begin()!=*kek2[j].rbegin()){
                ok=0;
            }
        }
        if (ok){
            if (i!=len(s)-1){
                ok=0;
                for (int j=a[i+1]+1;j<='a'+k-1;j++){
                    if (kek2[j].empty()){
                        if (kek1[s[i+1]].empty()){
                            ok=1;
                            break;
                        }
                        elif (*kek1[s[i+1]].begin()>a[i+1]){
                            ok=1;
                            break;
                        }
                    }
                    else{
                        if (*kek2[j].begin()==s[i+1]){
                            ok=1;
                            break;
                        }
                    }
                }
            }
            if (ok){
                l=i+1;
                break;
            }
        }
        if (i!=-1){
            kek1[s[i]].erase(kek1[s[i]].find(a[i]));
            kek2[a[i]].erase(kek2[a[i]].find(s[i]));
        }
    }
//    cout<<"l :: "<<l<<"\n";
    if (l==-1){
        cout<<"NO"<<"\n";
        return;
    }
    string t;
    build(t,l);
//    cout<<"t :: "<<t<<"\n";
    if (len(t)!=len(s)||t<a||t>b){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
        for (int i='a';i<='a'+k-1;i++){
            if (!what[i]){
                for (int j='a';j<='a'+k-1;j++){
                    if (!rwhat[j]){
                        what[i]=j;
                        rwhat[j]=i;
                        break;
                    }
                }
            }
        }
        string per="";
        for (int i='a';i<='a'+k-1;i++){
            per+=what[i];
        }
        cout<<per<<"\n";
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}