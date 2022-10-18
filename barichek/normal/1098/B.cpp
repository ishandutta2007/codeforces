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

#define arr (int)(3e5+10)

int num[ar];
char rnum[ar];
vector<int> cnt1[4][2];

signed dp1[arr][4][4];
signed from1[arr][4][4];
vector<int> cnt2[4][2];

signed dp2[arr][4][4];
signed from2[arr][4][4];

bool maximize(int& a,int b)
{
    if (a<b){
        a=b;
        return 1;
    }
    return 0;
}

char ans[arr][2];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    num['A']=0;
    num['G']=1;
    num['C']=2;
    num['T']=3;
    rnum[0]='A';
    rnum[1]='G';
    rnum[2]='C';
    rnum[3]='T';

    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for (auto& i:a){
        cin>>i;
    }
    for (int i=0;i<4;i++){
        cnt1[i][0].assign(m,0);
        cnt1[i][1].assign(m,0);
        cnt2[i][0].assign(n,0);
        cnt2[i][1].assign(n,0);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cnt1[num[a[i][j]]][i%2][j]++;
            cnt2[num[a[i][j]]][j%2][i]++;
        }
    }

    for (int i=0;i<arr;i++){
        for (int j=0;j<4;j++){
            for (int k=0;k<4;k++){
                dp1[i][j][k]=-1e9;
                dp2[i][j][k]=-1e9;
            }
        }
    }

    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (i!=j){
                dp1[0][i][j]=cnt1[i][0][0]+cnt1[j][1][0];
            }
        }
    }
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (i!=j){
                dp2[0][i][j]=cnt2[i][0][0]+cnt2[j][1][0];
            }
        }
    }

    for (int j=0;j+1<m;j++){
        for (int k1=0;k1<4;k1++){
            for (int k2=0;k2<4;k2++){
                if (k1!=k2){
                    for (int k3=0;k3<4;k3++){
                        if (k1!=k3&&k2!=k3){
                            int k4=0+1+2+3-k1-k2-k3;
                            if (maximize(dp1[j+1][k3][k4],dp1[j][k1][k2]+cnt1[k3][0][j+1]+cnt1[k4][1][j+1])){
                                from1[j+1][k3][k4]=k1*10+k2;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int j=0;j+1<n;j++){
        for (int k1=0;k1<4;k1++){
            for (int k2=0;k2<4;k2++){
                if (k1!=k2){
                    for (int k3=0;k3<4;k3++){
                        if (k1!=k3&&k2!=k3){
                            int k4=0+1+2+3-k1-k2-k3;
                            if (maximize(dp2[j+1][k3][k4],dp2[j][k1][k2]+cnt2[k3][0][j+1]+cnt2[k4][1][j+1])){
                                from2[j+1][k3][k4]=k1*10+k2;
                            }
                        }
                    }
                }
            }
        }
    }

    int best=-1;

    int kek1=-1;
    int kek2=-1;

    int type=-1;

    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (i!=j){
                if (dp1[m-1][i][j]>best){
                    best=dp1[m-1][i][j];
                    kek1=i;
                    kek2=j;
                    type=1;
                }
            }
        }
    }

    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (i!=j){
                if (dp2[n-1][i][j]>best){
                    best=dp2[n-1][i][j];
                    kek1=i;
                    kek2=j;
                    type=2;
                }
            }
        }
    }

//    cout<<best<<"\n";
//    cout<<kek1<<" "<<kek2<<"\n";

    if (type==1){
        ans[m-1][0]=rnum[kek1];
        ans[m-1][1]=rnum[kek2];
        for (int i=m-1;i>0;i--){
            int buf=from1[i][kek1][kek2];
            kek1=buf/10;
            kek2=buf%10;
            ans[i-1][0]=rnum[kek1];
            ans[i-1][1]=rnum[kek2];
        }

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout<<ans[j][i%2];
            }
            cout<<"\n";
        }
    }
    else{

        ans[n-1][0]=rnum[kek1];
        ans[n-1][1]=rnum[kek2];
        for (int i=n-1;i>0;i--){
            int buf=from2[i][kek1][kek2];
            kek1=buf/10;
            kek2=buf%10;
            ans[i-1][0]=rnum[kek1];
            ans[i-1][1]=rnum[kek2];
        }

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout<<ans[i][j%2];
            }
            cout<<"\n";
        }
    }
}