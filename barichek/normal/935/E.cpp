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

struct node
{
    int l,r;
    int left,right;

    node() {}
    node(int l,int r,int left,int right)
    {
        this->l=l;
        this->r=r;
        this->left=left;
        this->right=right;
    }
};

node a[arr];
int sz=0;

vi pos_in_deep[arr];

string s;

int dfs(int l,int r,int deep=1)
{
//    cerr<<"dfs :: "<<l<<" "<<r<<"\n";
    if (l==r){
//        cout<<"l==r :: "<<sz<<"\n";
        a[sz++]=*new node(l,r,-1,-1);
        return sz-1;
    }
    int pos=*lower_bound(all(pos_in_deep[deep]),l);
//    cerr<<"pos :: "<<pos<<"\n";
    int cur=sz;
    a[sz++]=*new node(l,r,-1,-1);
    a[cur].left=dfs(l+1,pos-1,deep+1);
    a[cur].right=dfs(pos+1,r-1,deep+1);
    return cur;
}

bool use[10001+10][2][101+10];
int dp[10001+10][2][101+10];
bool use1[10001+10][2][101+10];
int dp1[10001+10][2][101+10];

int flag=1;

int want_symbol;

int go1(int v,int is_minus,int cnt_plus);

int go(int v,int is_minus,int cnt_plus)
{
    if (a[v].l==a[v].r){
        if (cnt_plus==0){
//            cout<<"dp :: "<<v<<" "<<is_minus<<" "<<cnt_plus<<" :: "<<"with val :: "<<(s[a[v].l]-'0')<<"\n";
            return (s[a[v].l]-'0');
        }
        else{
//            cout<<"dp :: "<<v<<" "<<is_minus<<" "<<cnt_plus<<" :: "<<-1e9<<"\n";
            return -1e9;
        }
    }
    if (use[v][is_minus][cnt_plus]){
        return dp[v][is_minus][cnt_plus];
    }
    use[v][is_minus][cnt_plus]=1;
    int& res=dp[v][is_minus][cnt_plus];
    res=-1e9;
    for (int in_left=0;in_left<=cnt_plus;in_left++){
        for (int is_mid_minus=0;is_mid_minus<=1;is_mid_minus++){
            if (in_left+(is_mid_minus==want_symbol)<=cnt_plus){
                int current=go(a[v].left,is_minus,in_left)+(is_mid_minus?-go1(a[v].right,is_minus^is_mid_minus,cnt_plus-(in_left+(is_mid_minus==want_symbol))):go(a[v].right,is_minus^is_mid_minus,cnt_plus-(in_left+(is_mid_minus==want_symbol))));
                res=max(res,current);
            }
        }
    }
//    res=(1-2*is_minus)*res;
//    cout<<"dp :: "<<v<<" "<<is_minus<<" "<<cnt_plus<<" :: "<<res<<"\n";
    return res;
}

int go1(int v,int is_minus,int cnt_plus)
{
    if (a[v].l==a[v].r){
        if (cnt_plus==0){
//            cout<<"dp :: "<<v<<" "<<is_minus<<" "<<cnt_plus<<" :: "<<"with val :: "<<(s[a[v].l]-'0')<<"\n";
            return (s[a[v].l]-'0');
        }
        else{
//            cout<<"dp :: "<<v<<" "<<is_minus<<" "<<cnt_plus<<" :: "<<-1e9<<"\n";
            return +1e9;
        }
    }
    if (use1[v][is_minus][cnt_plus]){
        return dp1[v][is_minus][cnt_plus];
    }
    use1[v][is_minus][cnt_plus]=1;
    int& res=dp1[v][is_minus][cnt_plus];
    res=+1e9;
    for (int in_left=0;in_left<=cnt_plus;in_left++){
        for (int is_mid_minus=0;is_mid_minus<=1;is_mid_minus++){
            if (in_left+(is_mid_minus==want_symbol)<=cnt_plus){
                int current=go1(a[v].left,is_minus,in_left)+(is_mid_minus?-go(a[v].right,is_minus^is_mid_minus,cnt_plus-(in_left+(is_mid_minus==want_symbol))):go1(a[v].right,is_minus^is_mid_minus,cnt_plus-(in_left+(is_mid_minus==want_symbol))));
                res=min(res,current);
            }
        }
    }
//    res=(1-2*is_minus)*res;
//    cout<<"dp :: "<<v<<" "<<is_minus<<" "<<cnt_plus<<" :: "<<res<<"\n";
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>s;
    if (len(s)==1){
        cout<<s[0]-'0'<<"\n";
        return 0;
    }
    int p,m;
    cin>>p>>m;
    int cur=0;
    int pos=0;
    for (auto i:s){
        if (i=='('){
            cur++;
        }
        elif (i==')'){
            cur--;
        }
        elif (i=='?'){
            pos_in_deep[cur].pb(pos);
        }
        pos++;
    }
    int root=dfs(0,len(s)-1);
//    if (flag){
//        answer*=-1;
//    }
    int answer=0;
    if (p<=m){
        want_symbol=0;
        answer=go(root,0,p);
    }
    else{
        want_symbol=1;
        answer=go(root,0,m);
    }
//    int answer=0;
//    if (flag){
//        answer=go(root,0,p);
//    }
//    else{
//        answer=go1(root,0,m);
//    }
    cout<<answer<<"\n";
}