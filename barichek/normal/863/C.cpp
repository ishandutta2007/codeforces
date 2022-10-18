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
const ll md=1e9+7;

///---program start---///

int A[ar][ar];
int B[ar][ar];

void next(int& a,int& b)
{
    int aa=a;
    int bb=b;
    a=A[aa][bb];
    b=B[aa][bb];
}

void kek(int& ans1,int& ans2,int a,int b)
{
    if (a==b){
        return;
    }
    if (a==3&&b==2){
        ans1++;
    }
    if (a==2&&b==1){
        ans1++;
    }
    if (a==1&&b==3){
        ans1++;
    }
    swap(a,b);
    if (a==3&&b==2){
        ans2++;
    }
    if (a==2&&b==1){
        ans2++;
    }
    if (a==1&&b==3){
        ans2++;
    }
    swap(a,b);
}

int had[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int k,a,b;
    cin>>k>>a>>b;
    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++){
            cin>>A[i][j];
        }
    }
    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++){
            cin>>B[i][j];
        }
    }

    if (k<=100){
        int answer1=0;
        int answer2=0;
        while (k--){
            kek(answer1,answer2,a,b);
            next(a,b);
        }
        cout<<answer1<<" "<<answer2<<"\n";
        return 0;
    }

    int len_cyrcle=0;
    int kek1=a;
    int kek2=b;
    had[a][b]=1;
    next(a,b);
    len_cyrcle=1;
    int to_do=0;
    while (1){
//        cerr<<a<<" "<<b<<"\n";
        if (had[a][b]){
            len_cyrcle-=had[a][b]-1;
            to_do=had[a][b]-1;
            break;
        }
        len_cyrcle++;
        had[a][b]=len_cyrcle;
        next(a,b);
    }
//    cout<<len_cyrcle<<"\n";
//    cout<<to_do<<"\n";
    int answer1=0;
    int answer2=0;
    a=kek1;
    b=kek2;
    while (to_do--){
        k--;
        kek(answer1,answer2,a,b);
        next(a,b);
    }
//    cout<<answer1<<" "<<answer2<<"\n";

    int a1=0;
    int a2=0;
    int lol=k%len_cyrcle;
//    cout<<"lol :: "<<lol<<"\n";

    int aa=a;
    int bb=b;
//    cout<<aa<<" "<<bb<<"\n";
    while (lol--){
        kek(a1,a2,aa,bb);
        next(aa,bb);
    }

    int full_circle=k/len_cyrcle;
    int ans1=0;
    int ans2=0;
    while (len_cyrcle--){
        kek(ans1,ans2,a,b);
        next(a,b);
    }
    answer1+=ans1*full_circle+a1;
    answer2+=ans2*full_circle+a2;
    cout<<answer1<<" "<<answer2<<"\n";
}