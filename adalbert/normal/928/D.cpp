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

struct node
{
    vi go;
    int cnt_end;
    int cnt_down;

    node()
    {
        go.assign(26,0);
        cnt_end=0;
        cnt_down=0;
    }
};

node nodes[600000+10];
int sz_nodes=1;
int root=0;

int new_node()
{
    return sz_nodes++;
}

unordered_map<string,bool> have;

void add_string(string& s)
{
    if (have[s]){
        return;
    }
    have[s]=1;
    int cur=root;
    for (auto i:s){
        if (!nodes[cur].go[i-'a']){
            nodes[cur].go[i-'a']=new_node();
        }
        cur=nodes[cur].go[i-'a'];
        nodes[cur].cnt_down++;
    }
    nodes[cur].cnt_end++;
}

int get(string s)
{
//    cout<<"get :: "<<s<<" ";
    int cur=root;
    for (int i=0;i<len(s);i++){
        if (!nodes[cur].go[s[i]-'a']){
//            cout<<"dont find any"<<"\n";
            return 0;
        }
        cur=nodes[cur].go[s[i]-'a'];
        if (nodes[cur].cnt_down==0){
//            cout<<"dont find any"<<"\n";
            return 0;
        }
        if (nodes[cur].cnt_down==1){
//            cout<<"start find after :: "<<s.substr(0,i+1)<<"\n";
            for (int j=i+1;j<len(s);j++){
                if (!nodes[cur].go[s[j]-'a']){
//                    cout<<"cant go for prefix "<<s.substr(0,j+1)<<"\n";
                    return 0;
                }
                cur=nodes[cur].go[s[j]-'a'];
                if (nodes[cur].cnt_end==1){
//                    cout<<"return because of prefix "<<s.substr(0,j+1)<<"\n";
                    return j-i;
                }
            }
            return 0;
        }
    }
//    cout<<"dont find any"<<"\n";
    return 0;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    string s="";
    string t;
    while (getline(cin,t)){
        s+=t;
        s+=" ";
    }
    int ans=0;
    string cur="";
    for (auto i:s){
        if ('a'<=i&&i<='z'){
            cur+=i;
        }
        elif (!cur.empty()){
            ans+=max(0,get(cur)-1);
//            cout<<"new ans :: "<<ans<<"\n";
            add_string(cur);
            cur="";
        }
    }
    if (!cur.empty()){
        ans+=max(0,get(cur)-1);
//        cout<<"new ans :: "<<ans<<"\n";
        add_string(cur);
        cur="";
    }
    cout<<len(s)-ans<<"\n";
}