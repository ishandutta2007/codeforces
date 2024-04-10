#include <cstdio>
#include <cctype>
#include <string>

#define debug(...) fprintf(stderr,__VA_ARGS__);
#define Debug if(DEBUG)

using std::string;

namespace Template {
    struct IN {
        template<class T>void fr(T &a) {
            T s=0; int w=1; char ch=getchar();
            while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar();}
            while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
            a=w*s;
        }
        template<class T>T fr() {T a; fr(a); return a;}
        IN& operator >> (long long &x) {return fr(x),*this;}
        IN& operator >> (signed &x) {return fr(x),*this;}
        IN& operator >> (unsigned &x) {return fr(x),*this;}
        IN& operator >> (char &c) {
            while(isspace(c=getchar()));
            return *this;
        }
        IN& operator >> (string &str) {
            char ch;
            while(isspace(ch=getchar())) ; str=ch;
            while(!isspace(ch=getchar())) str+=ch;
            return *this;
        }
    }cin;
    struct OUT {
        char D[1<<28],*A=D-1;
        ~OUT() {fwrite(D,1,A-D+1,stdout);}
        template<class T>void fw(T x) {
            static char C[20];static int f;
            x<0?*++A='-',x=-x:0;
            while(C[++f]=48+x%10,x/=10) ;
            while(*++A=C[f],--f) ;
        }
        OUT& operator << (char c) {return *++A=c,*this;}
        OUT& operator << (string str) {
            int len=str.length();
            for(int i=0;i<len;i++) *++A=str[i];
            return *this;
        }
        OUT& operator << (long long x) {return fw(x),*this;}
        OUT& operator << (signed x) {return fw(x),*this;}
        OUT& operator << (unsigned x) {return fw(x),*this;}
    }cout;
    char endl='\n'; int DEBUG=0;
    template<class T>T sqr(T a) {return a*a;}
    template<class T>T abs(T a) {return a<0?-a:a;}
    template<class T>T cmin(T a,T b) {return a<b?a:b;}
    template<class T>T cmax(T a,T b) {return a>b?a:b;}
    template<class T>void cswp(T &a,T &b) {T t=a; a=b; b=t;}
}
using namespace Template;

const int N=1e3,P=2520;

bool book[N+10][P+10];
int w[N+10],dep[N+10][P+10],e[N+10][15],sz[N+10],stk[N*P+10],cnt[N+10],ans[N+10][P+10];

int dfs(int x,int y) {
	book[x][y]=1;
	if(ans[x][y]) return ans[x][y];
	stk[dep[x][y]]=x;
	int dx=e[x][y%sz[x]],dy=(y+w[dx])%P;
	if(book[dx][dy]) {
		if(ans[dx][dy]) return ans[x][y]=ans[dx][dy];
		int l=dep[dx][dy],r=dep[x][y];
		for(int i=l;i<=r;i++) cnt[stk[i]]=0;
		for(int i=l;i<=r;i++) if(cnt[stk[i]]==0) cnt[stk[i]]=1,ans[x][y]++;
		return ans[x][y];
	}
	dep[dx][dy]=dep[x][y]+1;
	return ans[x][y]=dfs(dx,dy);
}

int main() {
    #ifndef ONLINE_JUDGE
    DEBUG=1;
    #endif
    int n,q; cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i],w[i]=(w[i]%P+P)%P;
    for(int i=1;i<=n;i++) {
    	cin>>sz[i];
    	for(int j=0;j<sz[i];j++) cin>>e[i][j];
    }
	for(cin>>q;q;q--) {
		int x,c; cin>>x>>c;
		c=(c%P+P)%P;
		cout<<dfs(x,(c+w[x])%P)<<endl;
		// printf("%d\n",dfs(x,(c+w[x])%P));
	}
    return 0;
}