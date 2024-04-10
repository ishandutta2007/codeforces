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

#define ar (int)(1e4+10)

int z[ar];

void z_f(string s)
{
    memset(z,0,sizeof(z));
	for (int i=1,l=0,r=0;i<len(s);i++) {
		if (i<=r){
			z[i]=min(r-i+1,z[i-l]);
		}
		while (i+z[i]<len(s)&&s[z[i]]==s[i+z[i]]){
			z[i]++;
		}
		if (i+z[i]-1>r){
			l=i;
            r=i+z[i]-1;
		}
	}
}

int cnt[ar];
int val[ar][ar];
int dp[ar];

inline void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    for (int i=1;i<ar;i++){
        cnt[i]=cnt[i/10]+1;
    }

    for (int i=0;i<ar;i++){
        for (int j=0;j<ar;j++){
            val[i][j]=1e9;
            dp[i]=1e9;
        }
    }

    string s;
    cin>>s;
    for (int i=0;i<len(s);i++){
        string s1="";
        for (int j=i;j<len(s);j++){
            s1+=s[j];
        }
        z_f(s1);
        for (int j=1;j<=len(s);j++){
            for (int k=i+j;k<=len(s);k+=j){
                minimize(val[i][k-1],cnt[(k-i)/j]+j);
                if (k-i>len(s1)||z[k-i]<j){
                    break;
                }
            }
        }
    }
    dp[0]=0;
    for (int i=0;i<len(s);i++){
        for (int j=i+1;j<=len(s);j++){
            minimize(dp[j],dp[i]+val[i][j-1]);
        }
    }
    cout<<dp[len(s)]<<"\n";
}