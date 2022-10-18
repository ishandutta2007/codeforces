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

#define arr (int)(2e6+10)

map<int,int> vh;
int cnt_vh;

void do_vh()
{
    for (auto& i:vh){
        i.sec=cnt_vh++;
    }
}

int f[arr];

void upd(int pos,int val)
{
    for (int i=pos;i<arr;i|=i+1){
        f[i]=max(f[i],val);
    }
}

int get(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        res=max(res,f[i]);
    }
    return res;
}

int a[arr];
int b[arr];
int c[arr];
int vals[arr];

const bool cmp(const int& lhs,const int& rhs)
{
    return a[lhs]>a[rhs];
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for (int i=0;i<n;i++){
        scanf("%d",&c[i]);
        vh[a[i]];
        vh[b[i]];
        vh[c[i]];
        vals[i]=i;
    }
    do_vh();
    for (int i=0;i<n;i++){
        a[i]=vh[a[i]];
        b[i]=vh[b[i]];
        c[i]=vh[c[i]];
    }
    sort(vals,vals+n,cmp);
    int ans=0;
    for (int i=0;i<n;){
        int j=i;
        while (j<n&&a[vals[i]]==a[vals[j]]){
            j++;
        }
        /// [i;j)
        /// let i=j
        for (int k=i;k<j;k++){
            int A=a[vals[k]];
            int B=b[vals[k]];
            int C=c[vals[k]];
//            cout<<"get :: "<<A<<" "<<B<<" "<<C<<"\n";
//            cout<<"get :: "<<get(arr-(B+1))<<"\n";
            if (get(arr-(B+1))>C){
                ans++;
            }
        }
        for (int k=i;k<j;k++){
            int A=a[vals[k]];
            int B=b[vals[k]];
            int C=c[vals[k]];
//            cout<<"upd :: "<<A<<" "<<B<<" "<<C<<"\n";
            upd(arr-B,C);
        }
        i=j;
    }
    cout<<ans<<"\n";
}