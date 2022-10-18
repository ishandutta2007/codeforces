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

struct node
{
    node* p0;
    node* p1;
    int cnt;

    node()
    {
        p0=p1=0;
        cnt=0;
    }
};

node* root=new node();

const int M=62;

void add(int a)
{
    node* cur=root;
    for (int i=M-1;i>=0;i--){
        if (a&(1ll<<i)){
            if (!cur->p1){
                cur->p1=new node();
            }
            cur=cur->p1;
        }
        else{
            if (!cur->p0){
                cur->p0=new node();
            }
            cur=cur->p0;
        }
        cur->cnt++;
    }
}

void del(int a)
{
    node* cur=root;
    for (int i=M-1;i>=0;i--){
        if (a&(1ll<<i)){
            if (!cur->p1){
                cur->p1=new node();
            }
            cur=cur->p1;
        }
        else{
            if (!cur->p0){
                cur->p0=new node();
            }
            cur=cur->p0;
        }
        cur->cnt--;
    }
}

int get(int a)
{
//    cerr<<"getttt :: "<<a<<"\n";
    int res=-1;
    for (int i=M-1;i>=0;i--){
        int equal=M-1-i;
//        cerr<<"equal :: "<<equal<<" !!\n";
        node* cur=root;
        bool ok=1;
        int cur_res=0;
        for (int j=0;j<equal;j++){
            int num_in_a=M-1-j;
            cur_res+=(a&(1ll<<num_in_a));
            if (!cur->p0){
                ok=0;
                break;
            }
            cur=cur->p0;
        }
        if (ok){
            if (a&(1ll<<i)){
                if (cur->p1){
                    cur=cur->p1;
                    for (int j=i-1;j>=0;j--){
                        if (a&(1ll<<j)){
                            if (cur->p0&&cur->p0->cnt){
                                cur_res+=(1ll<<j);
                                cur=cur->p0;
                            }
                            elif (cur->p1){
                                cur=cur->p1;
                            }
                            else{
                                cur=0;
                                break;
                            }
                        }
                        else{
                            if (cur->p1&&cur->p1->cnt){
                                cur_res+=(1ll<<j);
                                cur=cur->p1;
                            }
                            elif (cur->p0){
                                cur=cur->p0;
                            }
                            else{
                                cur=0;
                                break;
                            }
                        }
                    }
                    if (cur&&cur->cnt){
//                        cerr<<"equal pref :: "<<equal<<" :: "<<cur_res<<"\n";
                        res=max(res,cur_res);
                    }
                }
            }
        }
    }
    return res;
}

int a[arr];
int b[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>b[i];
        add(b[i]);
        a[n]^=b[i];
    }
    for (int i=n-1;i>=0;i--){
        a[i]=get(a[i+1]);
//        cerr<<"i find a["<<i<<"] :: "<<a[i]<<"\n";
        if (a[i]==-1){
            return cout<<"No"<<"\n", 0;
        }
        del(a[i+1]^a[i]);
        if (i==0&&a[i]!=0){
            return cout<<"No"<<"\n", 0;
        }
//        cerr<<string(20,'-')<<"\n";
    }
    cout<<"Yes"<<"\n";
    int kek=0;
    for (int i=1;i<=n;i++){
        cout<<(a[i]^a[i-1])<<" ";
    }
    cout<<"\n";
}