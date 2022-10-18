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

int cnt[(1ll<<12)][(1ll<<12)];
pair<pii,bool> cnt1_w[4][6*6*6*6][(1ll<<4)];

int type[arr];

int a[arr];

int w,n,q;

pair<pii,bool> get_kek(int p,int m,int mm)
{
    pair<pii,bool> res=mp(mp(0,0),0);
    for (int i=0;i<p;i++){
        int cur_type=m%6;
        m/=6;
        if (cur_type==0){
            if (mm&(1ll<<i)){

            }
            else{
                res.fir.fir^=(1ll<<i);
            }
        }
        if (cur_type==1){
            if (mm&(1ll<<i)){
                res.sec=1;
            }
            else{

            }
        }
        if (cur_type==2){
            if (mm&(1ll<<i)){
                res.fir.sec^=(1ll<<i);
            }
            else{

            }
        }
        if (cur_type==3){
            if (mm&(1ll<<i)){
                res.fir.sec^=(1ll<<i);
            }
            else{
                res.sec=1;
            }
        }
        if (cur_type==4){
            if (mm&(1ll<<i)){
                res.fir.fir^=(1ll<<i);
            }
            else{
                res.fir.sec^=(1ll<<i);
            }
        }
        if (cur_type==5){
            if (mm&(1ll<<i)){

            }
            else{
                res.fir.sec^=(1ll<<i);
            }
        }
    }
    return res;
}

int pw(int a,int n)
{
    int res=1;
    while (n--){
        res*=a;
    }
    return res;
}

void precalc()
{
    for (int p=1;p<=4;p++){
        for (int m=0;m<pw(6,p);m++){
            for (int mm=0;mm<(1ll<<p);mm++){
                cnt1_w[p-1][m][mm]=get_kek(p,m,mm);
            }
        }
    }
}

inline bool podmask(int a,int b)
{
    return ((a&b)==a);
}

int cnt1[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    precalc();

    fast;

    cin>>w>>n>>q;

    for (int i=0;i<n;i++){
        cin>>a[i];
        for (int j=0;j<(1ll<<w);j++){
            cnt[j][a[i]^j]++;
        }
        cnt1[a[i]]++;
    }
    for (int j=0;j<(1ll<<w);j++){
        for (int i=0;i<w;i++){
            for (int k=0;k<(1ll<<w);k++){
                if (k&(1ll<<i)){
                    cnt[j][k]+=cnt[j][k^(1ll<<i)];
                }
            }
        }
    }

    pair<pii,bool> lolik;
    pair<pii,bool> lolik1;
    pair<pii,bool> lolik2;
    pair<pii,bool> lolik3;

    if (w<=8){
        for (int i=0;i<q;i++){
            string s;
            cin>>s;
            int ans=0;
            for (int j=0;j<w;j++){
                if (s[j]=='A'){
                    type[j]=0;
                }
                if (s[j]=='O'){
                    type[j]=1;
                }
                if (s[j]=='X'){
                    type[j]=2;
                }
                if (s[j]=='a'){
                    type[j]=0+3;
                }
                if (s[j]=='o'){
                    type[j]=1+3;
                }
                if (s[j]=='x'){
                    type[j]=2+3;
                }
            }
            int mask_req=0;
            int mask_req_first_4=0;
            int mask_req_after_4_before_8=0;
            int mask_req_after_8_before_12=0;

            if (w<=4){
                for (int j=0;j<w;j++){
                    mask_req*=6;
                    mask_req+=type[j];
                }
            }
            elif (w<=8){
                for (int j=w-4;j<w;j++){
                    mask_req_first_4*=6;
                    mask_req_first_4+=type[j];
                }
                for (int j=0;j<w-4;j++){
                    mask_req_after_4_before_8*=6;
                    mask_req_after_4_before_8+=type[j];
                }
            }
            else{
                for (int j=w-4;j<w;j++){
                    mask_req_first_4*=6;
                    mask_req_first_4+=type[j];
                }
                for (int j=w-8;j<w-4;j++){
                    mask_req_after_4_before_8*=6;
                    mask_req_after_4_before_8+=type[j];
                }
                for (int j=0;j<w-8;j++){
                    mask_req_after_8_before_12*=6;
                    mask_req_after_8_before_12+=type[j];
                }
            }

            for (int j=0;j<(1ll<<w);j++){
    //            cout<<bitset<1>(j)<<"\n";
                if (w<=4){
                    lolik=cnt1_w[w-1][mask_req][j];
                }
                elif (w<=8){
                    lolik1=cnt1_w[4-1][mask_req_first_4][j&((1ll<<4)-1)];
                    lolik2=cnt1_w[w-4-1][mask_req_after_4_before_8][j>>4];
                    lolik.fir.fir=lolik1.fir.fir+((lolik2.fir.fir)<<4);
                    lolik.fir.sec=lolik1.fir.sec+((lolik2.fir.sec)<<4);
                    lolik.sec=lolik1.sec|lolik2.sec;
                }
                else{
                    lolik1=cnt1_w[4-1][mask_req_first_4][j&((1ll<<4)-1)];
                    lolik2=cnt1_w[4-1][mask_req_after_4_before_8][(j>>4)&((1ll<<4)-1)];
                    lolik3=cnt1_w[w-8-1][mask_req_after_8_before_12][j>>8];
                    lolik.fir.fir=lolik1.fir.fir+((lolik2.fir.fir)<<4)+((lolik3.fir.fir)<<8);
                    lolik.fir.sec=lolik1.fir.sec+((lolik2.fir.sec)<<4)+((lolik3.fir.sec)<<8);
                    lolik.sec=lolik1.sec|lolik2.sec|lolik3.sec;
                }
    //            cout<<"lolik :: "<<bitset<4>(lolik.fir.fir)<<" "<<bitset<4>(lolik.fir.sec)<<" "<<lolik.sec<<"\n";
                if (!lolik.sec){
                    ans+=(cnt[lolik.fir.sec][lolik.fir.fir]*cnt1[j]);
    //                if (podmask(j^lolik.fir.sec,lolik.fir.fir)){
    ////                    cout<<"podmask :)"<<"\n";
    //                    ans-=cnt1[0][j]*cnt1[0][j];
    //                    ans2+=cnt1[0][j]*(cnt1[0][j]+1)/2;
    //                }
                }
    //            cout<<"new anses :: "<<ans<<" "<<ans2<<"\n";
            }
    //        cout<<"----------------------"<<"\n";
            cout<<ans<<"\n";
        }
    }
    else{
        map<string,int> answer;

        for (int i=0;i<q;i++){
            string s;
            cin>>s;
            int ans=0;
            for (int j=0;j<w;j++){
                if (s[j]=='A'){
                    type[j]=0;
                }
                if (s[j]=='O'){
                    type[j]=1;
                }
                if (s[j]=='X'){
                    type[j]=2;
                }
                if (s[j]=='a'){
                    type[j]=0+3;
                }
                if (s[j]=='o'){
                    type[j]=1+3;
                }
                if (s[j]=='x'){
                    type[j]=2+3;
                }
            }
            int mask_req_first_4=0;
            int mask_req_after_4_before_8=0;
            int mask_req_after_8_before_12=0;

            for (int j=w-4;j<w;j++){
                mask_req_first_4*=6;
                mask_req_first_4+=type[j];
            }
            for (int j=w-8;j<w-4;j++){
                mask_req_after_4_before_8*=6;
                mask_req_after_4_before_8+=type[j];
            }
            for (int j=0;j<w-8;j++){
                mask_req_after_8_before_12*=6;
                mask_req_after_8_before_12+=type[j];
            }

            if (answer.count(s)){
                cout<<answer[s]<<"\n";
                continue;
            }

            for (int j=0;j<(1ll<<w);j++){
                lolik1=cnt1_w[4-1][mask_req_first_4][j&((1ll<<4)-1)];
                lolik2=cnt1_w[4-1][mask_req_after_4_before_8][(j>>4)&((1ll<<4)-1)];
                lolik3=cnt1_w[w-8-1][mask_req_after_8_before_12][j>>8];
                lolik.fir.fir=lolik1.fir.fir+((lolik2.fir.fir)<<4)+((lolik3.fir.fir)<<8);
                lolik.fir.sec=lolik1.fir.sec+((lolik2.fir.sec)<<4)+((lolik3.fir.sec)<<8);
                lolik.sec=lolik1.sec|lolik2.sec|lolik3.sec;
    //            cout<<"lolik :: "<<bitset<4>(lolik.fir.fir)<<" "<<bitset<4>(lolik.fir.sec)<<" "<<lolik.sec<<"\n";
                if (!lolik.sec){
                    ans+=(cnt[lolik.fir.sec][lolik.fir.fir]*cnt1[j]);
    //                if (podmask(j^lolik.fir.sec,lolik.fir.fir)){
    ////                    cout<<"podmask :)"<<"\n";
    //                    ans-=cnt1[0][j]*cnt1[0][j];
    //                    ans2+=cnt1[0][j]*(cnt1[0][j]+1)/2;
    //                }
                }
    //            cout<<"new anses :: "<<ans<<" "<<ans2<<"\n";
            }
    //        cout<<"----------------------"<<"\n";
            answer[s]=ans;
            cout<<ans<<"\n";
        }
    }
}