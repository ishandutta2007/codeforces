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

int cnt[arr];

oryshych_jebosh()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    for (auto i:s){
        cnt[i]++;
    }
    cnt['1']--;
    cnt['6']--;
    cnt['8']--;
    cnt['9']--;
    int cur=0;
    for (int i='1';i<='9';i++){
        for (int j=0;j<cnt[i];j++){
            cur=(cur*10+(i-'0'))%7;
        }
    }
    int kek=1;
    for (int j=0;j<cnt['0'];j++){
        kek*=10;
        kek%=7;
    }
    string lol="1689";
    sort(all(lol));
    do{
        int cur1=0;
        for (auto i:lol){
            cur1=cur1*10+(i-'0');
            cur1%=7;
        }
//        cout<<"all :: "<<cur<<" "<<lol<<" "<<kek<<"\n";
//        cout<<"value :: "<<(cur*10000*kek%7+cur1*kek)%7<<"\n";
        if ((cur*10000*kek%7+cur1*kek)%7==0){
            for (int i='1';i<='9';i++){
                for (int j=0;j<cnt[i];j++){
                    cout<<char(i);
                }
            }
            cout<<lol;
            for (int j=0;j<cnt['0'];j++){
                cout<<'0';
            }
            return 0;
        }
    }
    while (next_permutation(all(lol)));
}