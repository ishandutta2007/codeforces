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

char a[20][20];

bool check()
{
    for (int i=0;i<10;i++){
        for (int j=0;j<=5;j++){
            int cnt=0;
            for (int k=j;k<j+5;k++){
                if (a[i][k]=='X'){
                    cnt++;
                }
            }
            if (cnt==5){
                return true;
            }
        }
    }
    for (int i=0;i<10;i++){
        for (int j=0;j<=5;j++){
            int cnt=0;
            for (int k=j;k<j+5;k++){
                if (a[k][i]=='X'){
                    cnt++;
                }
            }
            if (cnt==5){
                return true;
            }
        }
    }
    for (int i=0;i<=5;i++){
        for (int j=0;j<=5;j++){
            int cnt=0;
            for (int k=0;k<5;k++){
                if (a[i+k][j+k]=='X'){
                    cnt++;
                }
            }
            if (cnt==5){
                return true;
            }
        }
    }
    for (int i=4;i<10;i++){
        for (int j=0;j<=5;j++){
            int cnt=0;
            for (int k=0;k<5;k++){
                if (a[i-k][j+k]=='X'){
                    cnt++;
                }
            }
            if (cnt==5){
                return true;
            }
        }
    }
    return false;
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

    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cin>>a[i][j];
        }
    }

    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            if (a[i][j]=='.'){
                a[i][j]='X';
                if (check()){
                    cout<<"YES";
                    return 0;
                }
                a[i][j]='.';
            }
    cout<<"NO";
}