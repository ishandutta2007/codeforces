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

int to_int(string s)
{
    stringstream stt;
    stt<<s;
    int res;
    stt>>res;
    return res;
}

string lol(string s)
{
    sort(all(s));
    return s;
    if (s[0]!='0'){
        return s;
    }
    char c='#';
    for (int i=0;i<len(s);i++){
        if (s[i]!='0'){
            c=s[i];
            s.erase(s.begin()+i);
            break;
        }
    }
    s=string(1,c)+s;
    return s;
}

int cnt[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    string t;
    cin>>t;
    if (len(s)<len(t)){
        sort(all(s),greater<char>());
        return cout<<s<<"\n", 0;
    }
    for (auto i:s){
        cnt[i]++;
    }
    bool had_smaller=0;
    for (int i=0;i<len(t);i++){
        for (char c=(had_smaller?'9':t[i]);c>='0'+(i==0);c--){
//            cout<<i<<" "<<c<<" :: "<<cnt[c]<<" !!!!!\n";
            if (cnt[c]){
                cnt[c]--;
                string kek="";
                for (int j='9';j>='0';j--){
                    for (int p=0;p<cnt[j];p++){
                        kek+=char(j);
                    }
                }
//                cout<<i<<" "<<c<<" :: "<<kek<<" :: "<<to_int(lol(kek))<<" "<<to_int(t.substr(i+1))<<"\n";
                if (had_smaller||i==len(t)-1||c<t[i]||to_int(lol(kek))<=to_int(t.substr(i+1))){
//                    cout<<c<<" !!!!$$$\n";
                    cout<<c;
                    had_smaller|=(c<t[i]);
//                    cout<<"new :: "<<had_smaller<<"\n";
                    break;
                }
                else{
                    cnt[c]++;
                }
            }
        }
    }
    cout<<"\n";
}