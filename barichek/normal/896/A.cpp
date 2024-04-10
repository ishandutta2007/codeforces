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

///---program start---///

string s="What are you doing at the end of the world? Are you busy? Will you save us?";
string s2="What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
string s1="What are you doing while sending \"";
string s3="\"? Are you busy? Will you send \"";
string s4="\"?";

int l[arr];

char get(int n,int k)
{
    if (l[n]<=k){
        return '.';
    }
    if (n==0){
        if (k>=len(s)){
            return '.';
        }
        return s[k];
    }

    if (k<len(s1)){
        return s1[k];
    }
    k-=len(s1);
    if (l[n-1]>k){
        return get(n-1,k);
    }
    k-=l[n-1];

    if (k<len(s3)){
        return s3[k];
    }
    k-=len(s3);
    if (l[n-1]>k){
        return get(n-1,k);
    }
    k-=l[n-1];

    if (k<len(s4)){
        return s4[k];
    }
    k-=len(s4);
    return '.';
}

void solve()
{
    int n,k;
    cin>>n>>k;
    k--;
    cout<<get(n,k);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    l[0]=len(s);
    for (int i=1;i<arr;i++){
        l[i]=min(md*md,2*l[i-1]+len(s2));
    }

    int q;
    cin>>q;
    while (q--){
        solve();
    }
}