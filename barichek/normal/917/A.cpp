#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

#define ar (int)(5000+10)

int a[arr];
int p[arr];

int min_val1[ar][ar];
int min_val2[ar][ar];

int cnt_left[arr];
vi cur;

inline bool check1(int l,int r)
{
//    cout<<"check1 ? :: "<<l<<" "<<r<<"\n";
    int min_val=min_val1[l][r];
    int val=min_val-(l==0?0:p[l-1])-(l==0?0:cnt_left[l-1]);
    if (val>=0){
        return 1;
//        cout<<" return 1"<<"\n";
    }
    else{
        return 0;
    }
}

inline bool check2(int l,int r)
{
//    cout<<"check2 ? :: "<<l<<" "<<r<<"\n";
    int min_val=min_val2[l][r];
    int val=min_val-(l==0?0:p[l-1])+0+(l==0?0:cnt_left[l-1]);
//    cout<<"val2 :: "<<val<<"\n";
    if (val>=0){
        return 1;
//        cout<<" return 1"<<"\n";
    }
    else{
        return 0;
    }
}

inline bool check22(int l,int r,int m,int val1)
{
//    cout<<"check2 ? :: "<<l<<" "<<r<<"\n";
    int min_val=min_val2[m+1][r];
    int val=min_val-(l==0?0:p[l-1])+val1+cnt_left[m];
//    cout<<"val2 :: "<<val<<"\n";
    if (val>=0){
        return 1;
//        cout<<" return 1"<<"\n";
    }
    else{
        return 0;
    }
}

int get(int l,int r)
{
    if ((r-l+1)%2!=0){
        return 0;
    }
    int cnt1=cnt_left[r]-(l==0?0:cnt_left[l-1]);
    int sum=p[r]-(l==0?0:p[l-1]);
    if (abs(sum)>cnt1){
        return 0;
    }
//    cout<<l<<" "<<r<<"\n";
    int m=(cnt1-sum)/2; /// cnt+
//    cout<<"m :: "<<m<<" !!\n";
//    cout<<"cur[m-1] :: "<<cur[m-1]<<" !!\n";

    /// easy
    if (m==0){
        if (check2(l,r)){
            return 1;
        }
        else{
            return 0;
        }
    }
    elif (cur[m-1]==r){
//        cout<<"kek"<<"\n";
        if (check1(l,r)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        m=cur[m-1];
        if (check1(l,m)&&check22(l,r,m,cnt_left[m]-(l==0?0:cnt_left[l-1]))){
            return 1;
        }
        else{
            return 0;
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    int n=len(s);
    for (int i=0;i<n;i++){
        if (s[i]=='('){
            a[i]=1;
        }
        elif (s[i]==')'){
            a[i]=-1;
        }
        else{
            a[i]=0;
//            cout<<"bleat "<<i<<"\n";
        }
        cnt_left[i]=(i==0?0:cnt_left[i-1])+(a[i]==0);
        p[i]=(i==0?0:p[i-1])+a[i];
    }

    /// min_val1
    for (int i=0;i<n;i++){
        int val=2e9;
        for (int j=i;j<n;j++){
            val=min(val,p[j]+cnt_left[j]);
            min_val1[i][j]=val;
        }
    }

    /// min_val2
    for (int i=0;i<n;i++){
        int val=2e9;
        for (int j=i;j<n;j++){
            val=min(val,p[j]-cnt_left[j]);
            min_val2[i][j]=val;
        }
    }
    int ans=0;
    for (int i=0;i<n;i++){
//        cout<<"i :: "<<i<<"\n";
        cur.clear();
        for (int j=i;j<n;j++){
            if (a[j]==0){
//                cout<<"cur :: "<<j<<" !!!!\n";
                cur.pb(j);
            }
            ans+=get(i,j);
        }
    }
    cout<<ans<<"\n";
}