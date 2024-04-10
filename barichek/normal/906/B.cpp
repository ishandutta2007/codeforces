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

int sz;
pii bad[10*arr];

bool badly(pii cur)
{
    if (*lower_bound(bad,bad+sz,cur)==cur){
        return 1;
    }
    return 0;
}

bool ok(vi& kek,int n,int m)
{
    vector<vi> st(n,vi(m,0));
    int p=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            st[i][j]=kek[p++];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (i!=0){
                if (badly({st[i][j],st[i-1][j]})){
                    return 0;
                }
                if (badly({st[i-1][j],st[i][j]})){
                    return 0;
                }
            }
            if (j!=0){
                if (badly({st[i][j],st[i][j-1]})){
                    return 0;
                }
                if (badly({st[i][j-1],st[i][j]})){
                    return 0;
                }
            }
            if (i!=n-1){
                if (badly({st[i][j],st[i+1][j]})){
                    return 0;
                }
                if (badly({st[i+1][j],st[i][j]})){
                    return 0;
                }
            }
            if (j!=m-1){
                if (badly({st[i][j],st[i][j+1]})){
                    return 0;
                }
                if (badly({st[i][j+1],st[i][j]})){
                    return 0;
                }
            }
        }
    }
    return 1;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    srand(time(0));

    auto start=clock();

    int n,m;
    cin>>n>>m;
    if (n+m==3){
        return cout<<"NO"<<"\n", 0;
    }
    vector<vi> st(n,vi(m,0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            st[i][j]=i*m+j+1;
            //cout<<"st["<<i<<"]["<<j<<"] :: "<<st[i][j]<<"\n";
        }
    }
    if (n>=6&&m>=6){
        cout<<"YES"<<"\n";
        vi a1(0);
        vi a2(0);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if ((i+j)%2==0){
                    a1.pb(st[i][j]);
                }
                else{
                    a2.pb(st[i][j]);
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!a1.empty()){
                    cout<<a1.back()<<" ";
                    a1.pop_back();
                }  
                else{
                    cout<<a2.back()<<" ";
                    a2.pop_back();
                }
            }
            cout<<"\n";
        }
        return 0;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (i!=0){
                bad[sz++]={st[i][j],st[i-1][j]};
                bad[sz++]={st[i-1][j],st[i][j]};
            }
            if (j!=0){
                bad[sz++]={st[i][j],st[i][j-1]};
                bad[sz++]={st[i][j-1],st[i][j]};
            }
            if (i!=n-1){
                bad[sz++]={st[i][j],st[i+1][j]};
                bad[sz++]={st[i+1][j],st[i][j]};
            }
            if (j!=m-1){
                bad[sz++]={st[i][j],st[i][j+1]};
                bad[sz++]={st[i][j+1],st[i][j]};
            }
        }
    }
    bad[sz++]={md,md};
    sort(bad,bad+sz);
    
    for (int i=0;i<sz;i++){
        //cout<<bad[i].fir<<" "<<bad[i].sec<<"\n";
    }

    vi kek(0);
    for (int i=1;i<=n*m;i++){
        kek.pb(i);
    }
    while ((clock()-start)/CLOCKS_PER_SEC<=1.5){
        random_shuffle(all(kek));
        if (ok(kek,n,m)){
            cout<<"YES"<<"\n";
            for (int i=1;i<=n*m;i++){
                cout<<kek[i-1]<<" ";
                if (i%m==0){
                    cout<<"\n";
                }
            }
            return 0;
        }
    }
    cout<<"NO"<<"\n";
}