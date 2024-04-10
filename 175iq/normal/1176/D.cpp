#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
    char ch;
    bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    x = flag ? -x : x;
}
inline void write(int x) {
    static const int maxlen = 100;
    static char s[maxlen];
    if (x < 0) {   putchar('-'); x = -x;}
    if (!x) { putchar('0'); return; }
    int len = 0; for (; x; x /= 10) s[len++] = x % 10 + '0';
    for (int i = len - 1; i >= 0; --i) putchar(s[i]);
}

const int MAXN = 301000;
const int MAXval = 2950131;

int pos[  MAXval  ];
bool vis[ MAXval ];
int su[ MAXN ],cnt;
int from[ MAXval ];

void prepare(){
for (int i=2;i<MAXval;i++)
    {
        if (!vis[ i ] )
        {
            su[++cnt]=i;
            pos[ i ] =cnt;
        }
        for (int j=1;j<=cnt;j++)
            {
                if ( 1ll*i*su[j] >= MAXval )
                    break;
                from[ i*su[j] ] = i;
                vis[ i*su[j] ] = 1;
                if ( i%su[j] == 0 )
                    break;
            }
    }
}

int n;
int num[ MAXval ];
int ans[ MAXN ],tot;

int main(){
    prepare();
    //for (int i=2;i<=60;i++)
        //printf("from %d  = %d\n",i,from[i]);
    read(n);
    for (int i=1;i<=2*n;i++)
    {
        int x;
        read(x);
        num[x]++;
    }
    for (int i=MAXval-1;i>=2;i--)
        while ( num[i] )
        {
            int x=i;
            num[x] -- ;
            if ( vis[x] )
                {
                    ans[++tot] = x ;
                    num[ from[x] ] --;
                }
            else
                {
                    num[ pos[x] ] --;
                    ans[++tot] = pos[x] ;
                }
        }
    sort(ans+1,ans+tot+1);
    for (int i=1;i<tot;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[tot]);
    return 0;
}