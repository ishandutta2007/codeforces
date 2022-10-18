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

#define arr (int)(1e7)

int push[arr];
int t[arr]; /// vihodni
int sum[arr];
int value[arr];

void build(int v,int l,int r)
{
    if (l==r){
        return void(sum[v]=value[l]);
    }
    int m=(l+r)/2;
    build(v*2,l,m);
    build(v*2+1,m+1,r);
    sum[v]=sum[v*2]+sum[v*2+1];
}

inline void make_push(int v)
{
    if (!push[v]){
        return;
    }

    if (push[v]==1){
        t[v*2]=sum[v*2];
        t[v*2+1]=sum[v*2+1];
    }
    else{
        t[v*2]=0;
        t[v*2+1]=0;
    }

    push[v*2]=push[v*2+1]=push[v];
    push[v]=0;
}

int tl,tr;

void make1(int v,int l,int r)
{
    if (l>=tl&&r<=tr){
        t[v]=sum[v];
        push[v]=1;
        return;
    }
    if (l>tr||r<tl){
        return;
    }
    make_push(v);
    int m=(l+r)/2;
    make1(v*2,l,m);
    make1(v*2+1,m+1,r);
    t[v]=t[v*2]+t[v*2+1];
}

void make2(int v,int l,int r)
{
    if (l>=tl&&r<=tr){
        t[v]=0;
        push[v]=2;
        return;
    }
    if (l>tr||r<tl){
        return;
    }
    make_push(v);
    int m=(l+r)/2;
    make2(v*2,l,m);
    make2(v*2+1,m+1,r);
    t[v]=t[v*2]+t[v*2+1];
}

unordered_map<int,int> what;
map<int,int> vh;
int cnt_vh=0;

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
	if (buf_pos == buf_len) {
		buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
		if (buf_pos == buf_len)
			return 1;
	}
	return 0;
}

inline int getChar() {
	return isEof() ? -1 : buf[buf_pos++];
}

inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}

inline int readInt() {
	int s = 1, c = readChar();
	int x = 0;
	if (c == '-')
		s = -1, c = getChar();
	else if (c == '+')
		c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,q;
//    scanf("%d%d",&n,&q);
    n=readInt();
    q=readInt();
    vector<pair<int,pii>> a(q);
    for (auto& i:a){
        i.sec.fir=readInt();
        i.sec.sec=readInt();
        i.fir=readInt();
//        scanf("%d%d%d",&i.sec.fir,&i.sec.sec,&i.fir);
        vh[i.sec.fir];
        vh[i.sec.sec+1];
    }
    vh[1];
    vh[n+1];

    for (auto& i:vh){
        i.sec=++cnt_vh;
        what[i.fir]=i.sec;
    }
    for (auto it=vh.begin();next(it)!=vh.end();it++){
        value[it->sec]=next(it)->fir-it->fir;
//        cout<<"value["<<it->sec<<"] :: "<<value[it->sec]<<"\n";
    }
    build(1,1,cnt_vh);

    for (auto i:a){
        int type=i.fir;
        int l=i.sec.fir;
        int r=i.sec.sec;
        tl=what[l];
        tr=what[r+1]-1;
//        cout<<type<<" "<<l<<" "<<r<<" "<<vh[l]<<" "<<vh[r+1]<<"\n";
        if (type==1){
            make1(1,1,cnt_vh);
        }
        else{
            make2(1,1,cnt_vh);
        }
        cout<<n-t[1]<<"\n";
    }
}