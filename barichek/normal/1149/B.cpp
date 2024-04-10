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

string t[4];
int dp[251][251][251];
int N[arr][30];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<=250;i++){
        for (int j=0;j<=250;j++){
            for (int k=0;k<=250;k++){
                dp[i][j][k]=-1;
            }
        }
    }

    int n,q;
    string s;
    cin>>n>>q>>s;
    for (int j='a';j<='z';j++){
        N[len(s)][j-'a']=len(s);
    }
    for (int i=len(s)-1;i>=0;i--){
        for (int j='a';j<='z';j++){
            if (j!=s[i]){
                N[i][j-'a']=N[i+1][j-'a'];
            }
            else{
                N[i][j-'a']=i;
            }
        }
    }

    auto get_next=[&](int pos,char value)
    {
        if (pos==len(s)){
            return len(s);
        }
        else{
            return N[pos+1][value-'a'];
        }
    };

    auto minimize=[&](int& a,int b)
    {
        if (a>b){
            a=b;
        }
    };

    auto Do=[&]()
    {
        char c;
        cin>>c;
        if (c=='-'){
            int id;
            cin>>id;
            t[id].pop_back();
        }
        else{
            int id;
            char b;
            cin>>id>>b;
            t[id].pb(b);
            int l1=len(t[1]);
            int l2=len(t[2]);
            int l3=len(t[3]);
            if (id==1){
                for (int i2=0;i2<=l2;i2++){
                    for (int i3=0;i3<=l3;i3++){
                        dp[l1][i2][i3]=len(s);
                    }
                }
                for (int i2=0;i2<=l2;i2++){
                    for (int i3=0;i3<=l3;i3++){
                        minimize(dp[l1][i2][i3],
                                 get_next(dp[l1-1][i2][i3],t[1][l1-1]));
                        if (i2!=0){
                            minimize(dp[l1][i2][i3],
                                     get_next(dp[l1][i2-1][i3],t[2][i2-1]));
                        }
                        if (i3!=0){
                            minimize(dp[l1][i2][i3],
                                     get_next(dp[l1][i2][i3-1],t[3][i3-1]));
                        }
                    }
                }
            }
            if (id==2){
                for (int i1=0;i1<=l1;i1++){
                    for (int i3=0;i3<=l3;i3++){
                        dp[i1][l2][i3]=len(s);
                    }
                }
                for (int i1=0;i1<=l1;i1++){
                    for (int i3=0;i3<=l3;i3++){
                        if (i1!=0){
                            minimize(dp[i1][l2][i3],
                                     get_next(dp[i1-1][l2][i3],t[1][i1-1]));
                        }
                        minimize(dp[i1][l2][i3],
                                 get_next(dp[i1][l2-1][i3],t[2][l2-1]));
                        if (i3!=0){
                            minimize(dp[i1][l2][i3],
                                     get_next(dp[i1][l2][i3-1],t[3][i3-1]));
                        }
                    }
                }
            }
            if (id==3){
                for (int i1=0;i1<=l1;i1++){
                    for (int i2=0;i2<=l2;i2++){
                        dp[i1][i2][l3]=len(s);
                    }
                }
                for (int i1=0;i1<=l1;i1++){
                    for (int i2=0;i2<=l2;i2++){
                        if (i1!=0){
                            minimize(dp[i1][i2][l3],
                                     get_next(dp[i1-1][i2][l3],t[1][i1-1]));
                        }
                        if (i2!=0){
                            minimize(dp[i1][i2][l3],
                                     get_next(dp[i1][i2-1][l3],t[2][i2-1]));
                        }
                        minimize(dp[i1][i2][l3],
                                 get_next(dp[i1][i2][l3-1],t[3][l3-1]));
                    }
                }
            }
        }


        int l1=len(t[1]);
        int l2=len(t[2]);
        int l3=len(t[3]);

        if (dp[l1][l2][l3]<len(s)){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    };

    while (q--){
        Do();
    }
}