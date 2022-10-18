//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

bool maximize(int& a,int b)
{
    if (a<b){
        a=b;
        return 1;
    }
    return 0;
}

string to_str(int a)
{
    stringstream stt;
    stt<<a;
    string res;
    stt>>res;
    return res;
}

bool dp[201][201][4][4];
pair<bool,pii> from[201][201][4][4];

string ans1[201][201];
string ans2[201][201];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    dp[0][0][0][0]=1;
    for (int a=0;a<=200;a++){
        for (int b=0;b<=200;b++){
            for (int k=0;k<=3;k++){
                for (int kkk=0;kkk<=3;kkk++){
                    if (dp[a][b][k][kkk]){
                        if (max(k,kkk)==3){
                            continue;
                        }
                        if (k+kkk!=4){
                            for (int l=25;a+l<=200;l++){
                                if (l==25){
                                    for (int p=0;p<=23&&b+p<=200;p++){
                                        if (!dp[a+l][b+p][k+1][kkk]){
                                            dp[a+l][b+p][k+1][kkk]=1;
                                            from[a+l][b+p][k+1][kkk]=mp(0,mp(l,p));
                                        }
                                    }
                                }
                                else{
                                    for (int p=l-2;p<=l-2&&b+p<=200;p++){
                                        if (!dp[a+l][b+p][k+1][kkk]){
                                            dp[a+l][b+p][k+1][kkk]=1;
                                            from[a+l][b+p][k+1][kkk]=mp(0,mp(l,p));
                                        }
                                    }
                                }
                            }

                            for (int l=25;b+l<=200;l++){
                                if (l==25){
                                    for (int p=0;p<=23&&a+p<=200;p++){
                                        if (!dp[a+p][b+l][k][kkk+1]){
                                            dp[a+p][b+l][k][kkk+1]=1;
                                            from[a+p][b+l][k][kkk+1]=mp(0,mp(p,l));
                                        }
                                    }
                                }
                                else{
                                    for (int p=l-2;p<=l-2&&a+p<=200;p++){
                                        if (!dp[a+p][b+l][k][kkk+1]){
                                            dp[a+p][b+l][k][kkk+1]=1;
                                            from[a+p][b+l][k][kkk+1]=mp(0,mp(p,l));
                                        }
                                    }
                                }
                            }
                        }
                        else{
                            for (int l=15;a+l<=200;l++){
                                if (l==15){
                                    for (int p=0;p<=13&&b+p<=200;p++){
                                        if (!dp[a+l][b+p][k+1][kkk]){
                                            dp[a+l][b+p][k+1][kkk]=1;
                                            from[a+l][b+p][k+1][kkk]=mp(0,mp(l,p));
                                        }
                                    }
                                }
                                else{
                                    for (int p=l-2;p<=l-2&&b+p<=200;p++){
                                        if (!dp[a+l][b+p][k+1][kkk]){
                                            dp[a+l][b+p][k+1][kkk]=1;
                                            from[a+l][b+p][k+1][kkk]=mp(0,mp(l,p));
                                        }
                                    }
                                }
                            }

                            for (int l=15;b+l<=200;l++){
                                if (l==15){
                                    for (int p=0;p<=13&&a+p<=200;p++){
                                        if (!dp[a+p][b+l][k][kkk+1]){
                                            dp[a+p][b+l][k][kkk+1]=1;
                                            from[a+p][b+l][k][kkk+1]=mp(0,mp(p,l));
                                        }
                                    }
                                }
                                else{
                                    for (int p=l-2;p<=l-2&&a+p<=200;p++){
                                        if (!dp[a+p][b+l][k][kkk+1]){
                                            dp[a+p][b+l][k][kkk+1]=1;
                                            from[a+p][b+l][k][kkk+1]=mp(0,mp(p,l));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int a=0;a<=200;a++){
        for (int b=0;b<=200;b++){
//            cerr<<"AB :: "<<a<<" "<<b<<"\n";
            int res1=-1;
            int res2=-1;
            for (int k=0;k<=3;k++){
                for (int l=0;l<=3;l++){
//                    cerr<<a<<" "<<b<<" "<<k<<" "<<l<<"\n";
                    if (max(k,l)==3&&dp[a][b][k][l]&&(res1==-1||res1-res2<k-l)){
                        res1=k;
                        res2=l;
                    }
                }
            }

//            cerr<<a<<" "<<b<<"\n";
//            cerr<<" :: "<<res1<<" "<<res2<<"\n";

            if (res1==-1){
//                cerr<<"kek :: "<<a<<" "<<b<<"\n";
                ans1[a][b]="-1";
//                cerr<<"kek22 :: "<<a<<" "<<b<<"\n";
//                if (b==24){
//                    return 0;
//                }
            }
            else{
                ans1[a][b]=to_str(res1)+":"+to_str(res2);

                int aa=a;
                int bb=b;
                vector<pii> kek(0);
                while (res1||res2){
                    auto ff=from[aa][bb][res1][res2];
                    kek.pb(ff.sec);
                    aa-=ff.sec.fir;
                    bb-=ff.sec.sec;
                    if (ff.sec.fir>ff.sec.sec){
                        res1--;
                    }
                    else{
                        res2--;
                    }
                }
                reverse(all(kek));
                for (int i=0;i<len(kek);i++){
                    if (i){
                        ans2[a][b]+=" ";
                    }
                    ans2[a][b]+=to_str(kek[i].fir)+":"+to_str(kek[i].sec);
                }
            }

//            cerr<<"here :: "<<a<<" "<<b<<"\n";
        }
    }

    int q;
    cin>>q;
    while (q--){
        int a,b;
        cin>>a>>b;
        if (ans1[a][b]=="-1"){
            cout<<"Impossible"<<"\n";
        }
        else{
            cout<<ans1[a][b]<<"\n";
            cout<<ans2[a][b]<<"\n";
        }
    }
}