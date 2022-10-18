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
//#define int long long

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

int u[arr];
int v[arr];

int cost[arr];
vi lols[arr];

int num(int u,int v)
{
    if (u>v){
        swap(u,v);
    }
    if (u==1&&v==2){
        return 1;
    }
    if (u==1&&v==3){
        return 2;
    }
    if (u==1&&v==4){
        return 3;
    }
    if (u==2&&v==3){
        return 4;
    }
    if (u==2&&v==4){
        return 5;
    }
    if (u==3&&v==4){
        return 6;
    }
}

int pref[10][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    while (n--){
        int u,c,v;
        cin>>u>>c>>v;
        if (u==v){
            cost[u]+=c;
        }
        else{
            lols[num(u,v)].pb(c);
        }
    }
    for (int i=1;i<=6;i++){
        sort(all(lols[i]));
        reverse(all(lols[i]));
        for (int j=0;j<len(lols[i]);j++){
            pref[i][j]=(j==0?0:pref[i][j-1])+lols[i][j];
        }
    }
    vector<vector<vector<vector<vector<vector<vector<bool>>>>>>> dp;
    dp.resize(4);
    for (auto& i1:dp){
        i1.resize(len(lols[1])+1);
        for (auto& i2:i1){
            i2.resize(len(lols[2])+1);
            for (auto& i3:i2){
                i3.resize(len(lols[3])+1);
                for (auto& i4:i3){
                    i4.resize(len(lols[4])+1);
                    for (auto& i5:i4){
                        i5.resize(len(lols[5])+1);
                        for (auto& i6:i5){
                            i6.assign(len(lols[6])+1,0);
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for (int i=1;i<=4;i++){
        ans=max(ans,cost[i]);
        dp[i-1][0][0][0][0][0][0]=1;
    }
    #define lol(k,num) for (int k=0;k<=len(lols[num]);k++)

//    int min_len=1e9;
//    for (int i=1;i<=6;i++){
//        min_len=min(min_len,len(lols[i]));
//    }
    int barik_loh=0;
//    if (min_len>=5){
//        for (int i=1;i<=6;i++){
//            for (int j=0;j<5;j++){
//                barik_loh+=lols[i][0];
//                lols[i].erase(lols[i].begin());
//            }
//        }
//    }

    lol(k1,1)
    lol(k2,2)
    lol(k3,3)
    lol(k4,4)
    lol(k5,5)
    lol(k6,6){
        for (int j=1;j<=4;j++){
            if (dp[j-1][k1][k2][k3][k4][k5][k6]){
//                cerr<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<k6<<" :: "<<j<<"\n";
                if ((j==1||j==2)&&k1!=len(lols[1])){
                    dp[(1^2^j)-1][k1+1][k2][k3][k4][k5][k6]=1;
                }
                if ((j==1||j==3)&&k2!=len(lols[2])){
                    dp[(1^3^j)-1][k1][k2+1][k3][k4][k5][k6]=1;
                }
                if ((j==1||j==4)&&k3!=len(lols[3])){
                    dp[(1^4^j)-1][k1][k2][k3+1][k4][k5][k6]=1;
                }
                if ((j==2||j==3)&&k4!=len(lols[4])){
                    dp[(2^3^j)-1][k1][k2][k3][k4+1][k5][k6]=1;
                }
                if ((j==2||j==4)&&k5!=len(lols[5])){
                    dp[(2^4^j)-1][k1][k2][k3][k4][k5+1][k6]=1;
                }
                if ((j==3||j==4)&&k6!=len(lols[6])){
                    dp[(3^4^j)-1][k1][k2][k3][k4][k5][k6+1]=1;
                }
                int cur_ans=0;
                cur_ans+=(k1==0?0:pref[1][k1-1]);
                cur_ans+=(k2==0?0:pref[2][k2-1]);
                cur_ans+=(k3==0?0:pref[3][k3-1]);
                cur_ans+=(k4==0?0:pref[4][k4-1]);
                cur_ans+=(k5==0?0:pref[5][k5-1]);
                cur_ans+=(k6==0?0:pref[6][k6-1]);
                if (k1!=0||k2!=0||k3!=0){
                    cur_ans+=cost[1];
                }
                if (k1!=0||k4!=0||k5!=0){
                    cur_ans+=cost[2];
                }
                if (k2!=0||k4!=0||k6!=0){
                    cur_ans+=cost[3];
                }
                if (k3!=0||k5!=0||k6!=0){
                    cur_ans+=cost[4];
                }
                ans=max(ans,cur_ans);
            }
        }
    }
    cout<<ans+barik_loh<<"\n";
}