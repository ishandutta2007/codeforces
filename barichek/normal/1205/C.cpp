//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

bool ask(int x1,int y1,int x2,int y2)
{
    fflush(stdout);
    cout<<"?"<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
    fflush(stdout);
    int res;
    cin>>res;
    return res;
}

int ans[ar][ar];
int type[ar][ar];

main()
{
//    #ifdef Barik
//        files("barik");
//        freopen("debug.txt","w",stderr);
//    #endif

    int n;
    cin>>n;

    ans[1][1]=1;
    ans[2][2]=ans[1][1]^ask(1,1,2,2)^1;
    for (int i=3;i<=n;i+=2){
        ans[i][1]=ans[i-2][1]^ask(i-2,1,i,1)^1;
    }
    for (int i=4;i<=n;i+=2){
        ans[i][2]=ans[i-2][2]^ask(i-2,2,i,2)^1;
    }
    for (int i=1;i<=n;i+=2){
        for (int j=3;j<=n;j+=2){
            ans[i][j]=ans[i][j-2]^ask(i,j-2,i,j)^1;
        }
    }
    for (int i=2;i<=n;i+=2){
        for (int j=4;j<=n;j+=2){
            ans[i][j]=ans[i][j-2]^ask(i,j-2,i,j)^1;
        }
    }

    type[1][2]=0;
    type[2][3]=type[1][2]^ask(1,2,2,3)^1;
    type[2][1]=type[2][3]^ask(2,1,2,3)^1;
    for (int j=4;j<=n;j+=2){
        type[1][j]=type[1][j-2]^ask(1,j-2,1,j)^1;
    }
    for (int j=5;j<=n;j+=2){
        type[2][j]=type[2][j-2]^ask(2,j-2,2,j)^1;
    }
    for (int i=3;i<=n;i+=2){
        for (int j=2;j<=n;j+=2){
            type[i][j]=type[i-2][j]^ask(i-2,j,i,j)^1;
        }
    }
    for (int i=4;i<=n;i+=2){
        for (int j=1;j<=n;j+=2){
            type[i][j]=type[i-2][j]^ask(i-2,j,i,j)^1;
        }
    }

    bool answer=0;

    bool finded=0;
    int xx=-1;
    int yy=-1;
    for (int i=1;i<=n&&!finded;i++){
        for (int j=1;j<=n&&!finded;j++){
            if ((i+j)%2==0){
                if (i+1<=n&&j+2<=n&&ans[i][j]!=ans[i][j+2]&&type[i][j+1]!=type[i+1][j+2]){
                    finded=1;
                    bool cur_ask=ask(i,j,i+1,j+2);
                    if (cur_ask){
                        xx=i+1;
                        yy=j+2;
                        answer=type[i+1][j+2]^ans[i][j];
                    }
                    else{
                        xx=i+1;
                        yy=j+2;
                        answer=type[i+1][j+2]^ans[i][j]^1;
                    }
                }
                if (finded){
                    break;
                }
                if (i+2<=n&&j+1<=n&&ans[i][j]!=ans[i+2][j]&&type[i+1][j]!=type[i+2][j+1]){
                    finded=1;
                    bool cur_ask=ask(i,j,i+2,j+1);
                    if (cur_ask){
                        xx=i+2;
                        yy=j+1;
                        answer=type[i+2][j+1]^ans[i][j];
                    }
                    else{
                        xx=i+2;
                        yy=j+1;
                        answer=type[i+2][j+1]^ans[i][j]^1;
                    }
                }
                if (finded){
                    break;
                }
            }
            else{
                if (i+1<=n&&j+2<=n&&ans[i][j+1]!=ans[i+1][j+2]&&type[i][j]!=type[i][j+2]){
                    finded=1;
                    bool cur_ask=ask(i,j,i+1,j+2);
                    if (cur_ask){
                        xx=i;
                        yy=j;
                        answer=type[i][j]^ans[i+1][j+2];
                    }
                    else{
                        xx=i;
                        yy=j;
                        answer=type[i][j]^ans[i+1][j+2]^1;
                    }
                }
                if (finded){
                    break;
                }
                if (i+2<=n&&j+1<=n&&ans[i+1][j]!=ans[i+2][j+1]&&type[i][j]!=type[i+2][j]){
                    finded=1;
                    bool cur_ask=ask(i,j,i+2,j+1);
                    if (cur_ask){
                        xx=i;
                        yy=j;
                        answer=type[i][j]^ans[i+2][j+1];
                    }
                    else{
                        xx=i;
                        yy=j;
                        answer=type[i][j]^ans[i+2][j+1]^1;
                    }
                }
                if (finded){
                    break;
                }
            }
        }
    }

    if (!finded){
        for (int i=1;i<=n&&!finded;i++){
            for (int j=1;j<=n&&!finded;j++){
                if ((i+j)%2==0){
                    if (i+1<=n&&j+2<=n&&ans[i][j]==ans[i][j+2]&&type[i][j+1]==type[i+1][j+2]){
                        finded=1;
                        bool cur_ask=ask(i,j,i+1,j+2);
                        if (cur_ask){
                            xx=i+1;
                            yy=j+2;
                            answer=type[i+1][j+2]^ans[i][j];
                        }
                        else{
                            xx=i+1;
                            yy=j+2;
                            answer=type[i+1][j+2]^ans[i][j]^1;
                        }
                    }
                    if (finded){
                        break;
                    }
                    if (i+2<=n&&j+1<=n&&ans[i][j]==ans[i+2][j]&&type[i+1][j]==type[i+2][j+1]){
                        finded=1;
                        bool cur_ask=ask(i,j,i+2,j+1);
                        if (cur_ask){
                            xx=i+2;
                            yy=j+1;
                            answer=type[i+2][j+1]^ans[i][j];
                        }
                        else{
                            xx=i+2;
                            yy=j+1;
                            answer=type[i+2][j+1]^ans[i][j]^1;
                        }
                    }
                    if (finded){
                        break;
                    }
                }
                else{
                    if (i+1<=n&&j+2<=n&&ans[i][j+1]==ans[i+1][j+2]&&type[i][j]==type[i][j+2]){
                        finded=1;
                        bool cur_ask=ask(i,j,i+1,j+2);
                        if (cur_ask){
                            xx=i;
                            yy=j;
                            answer=type[i][j]^ans[i+1][j+2];
                        }
                        else{
                            xx=i;
                            yy=j;
                            answer=type[i][j]^ans[i+1][j+2]^1;
                        }
                    }
                    if (finded){
                        break;
                    }
                    if (i+2<=n&&j+1<=n&&ans[i+1][j]==ans[i+2][j+1]&&type[i][j]==type[i+2][j]){
                        finded=1;
                        bool cur_ask=ask(i,j,i+2,j+1);
                        if (cur_ask){
                            xx=i;
                            yy=j;
                            answer=type[i][j]^ans[i+2][j+1];
                        }
                        else{
                            xx=i;
                            yy=j;
                            answer=type[i][j]^ans[i+2][j+1]^1;
                        }
                    }
                    if (finded){
                        break;
                    }
                }
            }
        }
    }

    if (!finded){
        exit(1);
    }

    cout<<"!"<<"\n";
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if ((i+j)%2==0){
                cout<<ans[i][j];
            }
            else{
                cout<<(type[i][j]^answer);
            }
        }
        cout<<"\n";
    }
}