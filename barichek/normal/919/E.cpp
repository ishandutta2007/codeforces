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
///const ll md=1e9+7;

///---program start---///

#define arr (int)(1e6+10)

int len_cycle;
int have_pos_in_cycle[arr];
int pos_in_cycle[arr];
bool have[arr];

int a,b,p,x;

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*a%p;
        }
        n/=2;
        a=a*a%p;
    }
    return res;
}

int inv(int a,int m=p)
{
    return bpow(a,m-2);
}

int dop_ans[arr];

int L,R;

int get(int i)
{
//    cerr<<"get :: "<<i<<"\n";

    /// n==k*p+i==k*(p-1)+k+i
    /// a^(k+i)==b/i (mod p)
    /// a^k==b/(i*a^i) (mod p)
    int right=b;
    right=right*inv(i)%p;
    right=right*inv(bpow(a,i))%p;
//    cerr<<"right :: "<<right<<"\n";

    if (!have[right]){
        return 0;
    }

    /// how_much_k ?????????????????

    /// k*p+i<=x
    /// k*p<=x-i

    int max_k=(x-i)/p;
//    cerr<<"max_k :: "<<max_k<<"\n";

    int num=pos_in_cycle[right];
//    cerr<<"num :: "<<num<<"\n";
    if (!have_pos_in_cycle[right]){
        return (dop_ans[right]!=0&&dop_ans[right]-1<=max_k);
    }
    if (L-1>=max_k){
        return (dop_ans[right]!=0&&dop_ans[right]-1<=max_k);
    }
    else{
        int full_cycle=(max_k-L)/len_cycle;
        int left_in_cycle=(max_k-L)%len_cycle;
        return (dop_ans[right]!=0&&dop_ans[right]-1<=max_k)
                    +full_cycle+(num<=left_in_cycle);
    }
}

int naive()
{
    int answer=0;
    for (int i=1;i<=x;i++){
        if (i*bpow(a,i)%p==b){
            answer++;
        }
    }
    return answer;
}

int last[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>a>>b>>p>>x;
    assert(b!=0);

    #ifdef I_love_Maria_Ivanova
        cout<<"naive :: "<<naive()<<"\n";
    #endif

    if (a==1){
//        assert(0);
        if (x<b){
            cout<<0<<"\n";
        }
        else{
            cout<<1+(x-b)/p<<"\n";
        }
        return 0;
    }
    int cur=1;
    last[cur]=1;
    have[cur]=1;
    int cur_step=1;
    while (1){
        cur=cur*a%p;
        cur_step++;
        if (last[cur]){
            L=last[cur];
            R=cur_step-1;
            break;
        }
        last[cur]=cur_step;
        have[cur]=1;
    }
    L--;
    R--;
//    cout<<string(20,'-')<<"\n";
//    cout<<"L R :: "<<L<<" "<<R<<"\n";
    cur=1;
//    cout<<"before cycle :: "<<"\n";
    for (int i=0;i<L;i++){
        cout<<cur<<"\n";
        dop_ans[cur]=i+1;
        cur=cur*a%p;
    }
//    cout<<string(20,'-')<<"\n";
//    cout<<"cycle :: ";
    for (int i=L;i<=R;i++){
//        cout<<cur<<"\n";
        have_pos_in_cycle[cur]=1;
        pos_in_cycle[cur]=i-L;
        cur=cur*a%p;
        len_cycle++;
    }
//    cout<<string(20,'-')<<"\n";
//    cerr<<"cycle builded"<<"\n";
//    cerr<<"len_cycle :: "<<len_cycle<<"\n";
//    cout<<"len_cycle :: "<<len_cycle<<"\n";
    int ans=0;
    for (int i=1;i<min(p,x+1);i++){
        ans+=get(i);
    }
    cout<<ans<<"\n";
}