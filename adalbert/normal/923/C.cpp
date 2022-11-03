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
    int p0,p1;
    int cnt;

    node()
    {
        p0=0;
        p1=0;
        cnt=0;
    }
};

const int M=32;

node nodes[300000*M*2];
int root;
int cnt_nodes=0;

int new_node()
{
    return ++cnt_nodes;
}

void add(int a)
{
    int cur=root;
    for (int i=M-1;i>=0;i--){
        if (a&(1ll<<i)){
            if (!nodes[cur].p1){
                nodes[cur].p1=new_node();
            }
            cur=nodes[cur].p1;
        }
        else{
            if (!nodes[cur].p0){
                nodes[cur].p0=new_node();
            }
            cur=nodes[cur].p0;
        }
        nodes[cur].cnt++;
    }
}

void del(int a)
{
    int cur=root;
    for (int i=M-1;i>=0;i--){
        if (a&(1ll<<i)){
            if (!nodes[cur].p1){
                nodes[cur].p1=new_node();
            }
            cur=nodes[cur].p1;
        }
        else{
            if (!nodes[cur].p0){
                nodes[cur].p0=new_node();
            }
            cur=nodes[cur].p0;
        }
        nodes[cur].cnt--;
    }
}

int get_best(int a)
{
    int cur=root;
    int res=0;
    for (int i=M-1;i>=0;i--){
        if (a&(1ll<<i)){
            if (nodes[cur].p1&&nodes[nodes[cur].p1].cnt){
                cur=nodes[cur].p1;
                res+=(1ll<<i);
            }
            else{
                cur=nodes[cur].p0;
            }
        }
        else{
            if (nodes[cur].p0&&nodes[nodes[cur].p0].cnt){
                cur=nodes[cur].p0;
            }
            else{
                cur=nodes[cur].p1;
                res+=(1ll<<i);
            }
        }
    }
    return res;
}

#define arr (int)(3e5+10)

int a[arr];
int p[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        cin>>p[i];
        add(p[i]);
    }
    for (int i=0;i<n;i++){
        int cur=get_best(a[i]);
//        cout<<cur<<" !!!\n";
        cout<<(a[i]^cur)<<" ";
        del(cur);
    }
    cout<<"\n";
}