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
    int val;
    node* l;
    node* r;

    node()
    {
        val=0;
        l=0;
        r=0;
    }
};

void copy(node*& u,node* v)
{
    u->val=v->val;
    u->l=v->l;
    u->r=v->r;
}

node* copy(node* v)
{
    node* buf=new node();
    node*& u=buf;
    u->val=v->val;
    u->l=v->l;
    u->r=v->r;
    return buf; /// why not u ????
}

int get_val(node* v)
{
    return v?v->val:0;
}

void upd1(node*& v,int l,int r,int pos,int val)
{
//    if (l==1&&r==md){
//        cout<<"  upd1 :: "<<pos<<" "<<val<<"\n";
//    }
    if (l==r){
        v->val+=val;
        return;
    }
    int m=(l+r)/2;
    if (pos<=m){
        if (!v->l){
            v->l=new node();
        }
        v->l=copy(v->l);
        upd1(v->l,l,m,pos,val);
    }
    else{
        if (!v->r){
            v->r=new node();
        }
        v->r=copy(v->r);
        upd1(v->r,m+1,r,pos,val);
    }
    v->val=get_val(v->l)+get_val(v->r);
}

int get1(node* v,int l,int r,int tl,int tr)
{
//    if (l==1&&r==md){
//        cout<<"  get1 :: "<<tl<<" "<<tr<<"\n";
//    }
    if (l>tr||r<tl){
        return 0;
    }
    if (l>=tl&&r<=tr){
//        cout<<"return get1 :: "<<l<<" "<<r<<" :: "<<v->val<<"\n";
        return v->val;
    }
    if (!v->l){
        v->l=new node();
    }
    if (!v->r){
        v->r=new node();
    }
    v->l=copy(v->l);
    v->r=copy(v->r);
    int m=(l+r)/2;
    return get1(v->l,l,m,tl,tr)+get1(v->r,m+1,r,tl,tr);
}

void upd2(node*& v,int l,int r,int pos,int val)
{
//    cout<<"    upd2 :: "<<l<<" "<<r<<" || "<<pos<<" "<<val<<"\n";
    if (l==r){
        v->val=val;
        return;
    }
    int m=(l+r)/2;
    if (pos<=m){
        if (!v->l){
//            cout<<"      create new l"<<"\n";
            v->l=new node();
        }
        v->l=copy(v->l);
        upd2(v->l,l,m,pos,val);
    }
    else{
        if (!v->r){
//            cout<<"      create new r"<<"\n";
            v->r=new node();
        }
        v->r=copy(v->r);
        upd2(v->r,m+1,r,pos,val);
    }
}

int get2(node* v,int l,int r,int pos)
{
//    cout<<"    get2 :: "<<l<<" "<<r<<" || "<<pos<<"\n";
    if (!v){
//        cout<<"    thats end..."<<"\n";
        return 0;
    }
    if (l==r){
        return v->val;
    }
    int m=(l+r)/2;
    if (pos<=m){
        if (v->l){
//            cout<<"      i will go left :)"<<"\n";
            v->l=copy(v->l);
//            cout<<"      one moment to go left :)"<<"\n";
        }
        return get2(v->l,l,m,pos);
    }
    else{
        if (v->r){
            v->r=copy(v->r);
        }
        return get2(v->r,m+1,r,pos);
    }
}

void dfs(node* v,int l,int r)
{
    if (!v){
        return;
    }
    int m=(l+r)/2;
    dfs(v->l,l,m);
    cout<<"        "<<l<<" "<<r<<"\n";
    dfs(v->r,m+1,r);
}

void dfs(node* v)
{
    cout<<"      debug :: "<<"\n";
    dfs(v,1,md);
}

int get_hash(string s)
{
    int p=1;
    int res=0;
    for (int i=0;i<len(s);i++){
        res+=p*(s[i]-'a'+1);
        res%=md;
        p=(p*31)%md;
    }
    return res+1;
}

unordered_map<string,int> mapka;
int sz_mapka=0;

int read_hash()
{
    string s;
    cin>>s;
    return mapka.count(s)?mapka[s]:mapka[s]=++sz_mapka;
}

node* root1[arr]; /// 1 - is +1 -1
node* root2[arr]; /// is set value

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<arr;i++){
        root1[i]=new node();
        root2[i]=new node();
    }

//    root1[0]=new node();
//    root2[0]=new node();

    int q;
    cin>>q;
    for (int i=1;i<=q;i++){
        string type;
        cin>>type;
//        cout<<type<<" ";
        if (type=="set"){ /// ok
            int v=read_hash();
            int x;
            cin>>x;
//            cout<<v<<" "<<x<<"\n";

            copy(root2[i],root2[i-1]);
            copy(root1[i],root1[i-1]);

//            cout<<"want to find last..."<<"\n";
            int last=get2(root2[i],1,md,v);
//            cout<<"last :: "<<last<<"\n";

            if (last){
                upd1(root1[i],1,md,last,-1);
            }
            upd1(root1[i],1,md,x,+1);

            upd2(root2[i],1,md,v,x);
        }
        elif (type=="remove"){ /// ok
            int v=read_hash();
//            cout<<v<<"\n";

            copy(root2[i],root2[i-1]);
            copy(root1[i],root1[i-1]);

            int x=get2(root2[i],1,md,v);

            if (x){
                upd2(root2[i],1,md,v,0);
                upd1(root1[i],1,md,x,-1);
            }
        }
        elif (type=="query"){ /// ok
            int v=read_hash();
//            cout<<v<<"\n";

            copy(root2[i],root2[i-1]);
            copy(root1[i],root1[i-1]);

//            cout<<"    debug after all in query copy !!!"<<"\n";
//            cout<<"    root1[i]"<<"\n";
//            dfs(root1[i]);
//            cout<<"    root2[i]"<<"\n";
//            dfs(root2[i]);

            int x=get2(root2[i],1,md,v);

//            cout<<"  x :: "<<x<<"\n";
            if (!x){
                cout<<-1<<"\n";
            }
            else{
                cout<<(x==1?0:get1(root1[i],1,md,1,x-1))<<"\n";
            }

            fflush(stdout);
        }
        elif (type=="undo"){ /// !!!
            int d;
            cin>>d;
//            cout<<d<<"\n";
            int kek=max(0ll,i-d-1);

            copy(root2[i],root2[kek]);
            copy(root1[i],root1[kek]);
        }

//        cout<<"  now debug !!!"<<"\n";
//        cout<<"    root1[i]"<<"\n";
//        dfs(root1[i]);
//        cout<<"    root2[i]"<<"\n";
//        dfs(root2[i]);
    }
}