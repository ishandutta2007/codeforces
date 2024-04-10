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

int dist[ar][ar];
int min1[ar][30];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    for (int i=0;i<ar;i++){
        for (int j=0;j<30;j++){
            min1[i][j]=1e9;
        }
    }

    for (int i=0;i<1000;i++){
        for (int j=0;j<1000;j++){
            dist[i][j]+=(i/100!=j/100);
            dist[i][j]+=(i/10%10!=j/10%10);
            dist[i][j]+=(i%10!=j%10);
            int sum=j/100+j/10%10+j%10;
            min1[i][sum]=min(min1[i][sum],dist[i][j]);
        }
    }
    string s;
    cin>>s;
    int a1=(s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'0');
    int a2=(s[3]-'0')*100+(s[4]-'0')*10+(s[5]-'0');
    int ans=1e9;
    for (int i=0;i<30;i++){
        int cur_ans=0;
        cur_ans+=min1[a1][i]+min1[a2][i];
        ans=min(ans,cur_ans);
    }
    cout<<ans<<"\n";
}