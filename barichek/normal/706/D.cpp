#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

string to_bin(int a)
{
    string res="";
    while (a)
        res=res+char(a%2+'0'),
        a/=2;
    while (res.length()<32) res+='0';
    reverse(all(res));
    return res;
}

struct bor_node
{
    int next[2];
    int cnt;
    bor_node()
    {
        this->next[0]=NULL;
        this->next[1]=NULL;
        this->cnt=0;
    }
} bor[30*arr];

int cur=0;

void add_bor(int a)
{
    string use=to_bin(a);
    int now=0;
    for (auto i:use)
    {
        if (bor[now].next[i-'0'])
            now=bor[now].next[i-'0'];
        else
            now=bor[now].next[i-'0']=++cur;
        bor[now].cnt++;
    }
}

void delete_bor(int a)
{
    string use=to_bin(a);
    int now=0;
    for (auto i:use)
    {
        if (bor[now].next[i-'0'])
            now=bor[now].next[i-'0'];
        else
            now=bor[now].next[i-'0']=++cur;
        bor[now].cnt--;
    }
}

int _ans(int a)
{
    string use=to_bin(a);
    int now=0;
    int res=0;
    for (int i=0;i<use.length();i++)
    {
        if (bor[bor[now].next[1-use[i]+'0']].cnt)
            now=bor[now].next[1-use[i]+'0'],
            res+=(1<<(use.length()-i-1));
        elif (bor[bor[now].next[use[i]-'0']].cnt)
            now=bor[now].next[use[i]-'0'];
        else return res;
    }
    return res;
}

int main()
{
    for (int i=0;i<30*arr;i++)
        bor[i]=bor_node();
    int n;
    cin>>n;
    add_bor(0);
    while (n--)
    {
        char type;
        int a;
        cin>>type>>a;
        if (type=='+')
            add_bor(a);
        elif (type=='-')
            delete_bor(a);
        else cout<<_ans(a)<<"\n";
    }
}