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

#define oryshych_jebosh main

///---program start---///

pii stb[arr][15];
int lg[arr];
int ans[arr];
int n;

pii get(int L,int R)
{
//    cerr<<"get("<<L<<","<<R<<")"<<"\n";
    int lgg=lg[R-L+1];
//    assert(R-(1ll<<lgg)+1>=0);
//    if (n==100&&L==0){
//        assert(max(stb[L][lgg],stb[R-(1ll<<lgg)+1][lgg]).fir==1);
//    }
//    cerr<<"lgg :: "<<lgg<<"\n";
    return max(stb[L][lgg],stb[R-(1ll<<lgg)+1][lgg]);
}

oryshych_jebosh()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=2;i<arr;i++){
        lg[i]=lg[i/2]+1;
    }

    cin>>n;
    vector<pii> a(n);
    for (int i=0;i<len(a);i++){
        cin>>a[i].fir;
//        a[i].fir=1;
        a[i].sec=i;
    }

    sort(all(a));

    vector<pii> v(0);
    for (int i=0;i<len(a);i++){
        if (i==0||a[i].fir!=a[i-1].fir){
            v.pb(mp(a[i].fir,1));
        }
        else{
            v.back().sec++;
        }
    }

//    if (n==100){
//        cout<<"v :: "<<"\n";
//        for (auto i:v){
//            cout<<i.fir<<" "<<i.sec<<"\n";
//        }
//    }

//    if (n==100){
//        vi q(0);
//        for (auto i:a){
//            q.pb(i.fir);
//        }
//        assert(*min_element(all(q))==*max_element(all(q)));
//    }


    /// -----------------------------

    for (int i=0;i<len(a);i++){
        stb[i][0]=mp(a[i].fir-(i==0?0:a[i-1].fir),i);
    }

    for (int j=1;j<15;j++){
        for (int i=0;i+(1ll<<j)-1<len(a);i++){
            stb[i][j]=max(stb[i][j-1],stb[i+(1ll<<(j-1))][j-1]);
        }
    }

    /// -----------------------------


    int ans1=-1e9;
    int ans2=-1e9;
    int ans3=-1e9;
    int pos1=-1;
    int pos2=-1;
    int pos3=-1;

    for (int i=0;i<n-1;i++){
        for (int j=0;j<i;j++){
//            cout<<"i j :: "<<i<<" "<<j<<"\n";
            int cnt1=n-i-1;
            int cnt2=i-j;
//            cout<<"cnth's :: "<<cnt1<<" "<<cnt2<<"\n";
            if (cnt1<=2*cnt2&&cnt2<=2*cnt1){
                /// k
                int Lk=0,Rk=j;
//                Rk=min(Rk,2*min(cnt1,cnt2));
                Lk=max(Lk,j+1-2*min(cnt1,cnt2)); ///

//                Lk=max(Lk,(max(cnt1,cnt2)+1)/2);
                Rk=min(Rk,2*j+2-max(cnt1,cnt2)<0?-1:(2*j+2-max(cnt1,cnt2))/2); ///

//                Rk=min(Rk,(2*j+2)/3);
//                Lk=max(Lk,(j+1+2)/3);

//                cout<<"Lk Rk :: "<<Lk<<" "<<Rk<<"\n";

//                for (int k=0;k<=j;k++){
//                    int cnt3=j-k+1;
//                    if (cnt3<=2*cnt1&&cnt3<=2*cnt2&&cnt1<=2*cnt3&&cnt2<=2*cnt3){
//                        if (k>Rk||k<Lk){
//                            cout<<k<<" "<<i<<" "<<j<<" !!!!111111\n";
//                            exit(1);
//                        }
//                    }
//                    else{
//                        if (k>=Lk&&k<=Rk){
//                            cout<<k<<" "<<i<<" "<<j<<" !!!!222222\n";
//                            exit(1);
//                        }
//                    }
//                }
                if (Lk>Rk){
                    continue;
                }
                int k=get(Lk,Rk).sec;

//                cerr<<"k :: "<<k<<"\n";

                int cur_ans1=a[i+1].fir-a[i].fir;
//                cerr<<"kek1"<<"\n";
                int cur_ans2=a[j+1].fir-a[j].fir;
//                cerr<<"kek2"<<"\n";
                int cur_ans3=a[k].fir-(k==0?0:a[k-1].fir);
//                cerr<<"kek3"<<"\n";
                if (mp(ans1,mp(ans2,ans3))<mp(cur_ans1,mp(cur_ans2,cur_ans3))){
                    ans1=cur_ans1;
                    ans2=cur_ans2;
                    ans3=cur_ans3;
                    pos1=i;
                    pos2=j;
                    pos3=k;
//                    if (n==100){
//                        cout<<"set ans :: "<<i<<" "<<j<<" "<<k<<"\n";
//                        cout<<"ans :: "<<ans1<<" "<<ans2<<" "<<ans3<<"\n";
//                    }
                }
            }
        }
    }

    assert(pos1!=-1);

//    cerr<<"results :: "<<"\n";
//    cerr<<"pos1 :: "<<pos1<<"\n";
//    cerr<<"pos2 :: "<<pos2<<"\n";
//    cerr<<"pos3 :: "<<pos3<<"\n";

    for (int i=0;i<pos3;i++){
        ans[a[i].sec]=-1;
    }
    assert(pos3<=pos2);
    for (int i=pos3;i<=pos2;i++){
        ans[a[i].sec]=3;
    }
    assert(pos2+1<=pos1);
    for (int i=pos2+1;i<=pos1;i++){
        ans[a[i].sec]=2;
    }
    assert(pos1+1<n);
    for (int i=pos1+1;i<n;i++){
        ans[a[i].sec]=1;
    }
    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}