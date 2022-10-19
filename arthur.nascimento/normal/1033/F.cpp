#include <bits/stdc++.h>
#define pii pair<int,char>
#define maxn (1<<24)
#define debug 
typedef long long ll;
using namespace std;

map<pii,short> mp;

char str[15];
short v[maxn];
int f[4040];
int s[2][15];
int w;

char foi[maxn];
short fast[maxn];

inline int get(int num,int pos){
    if(pos == 0 && foi[num])
        return fast[num];
    if(mp.find(pii(num,pos)) != mp.end())   
        return mp[pii(num,pos)];
    if(pos == 2*w)
        return v[num];
    int r = 0;
    if(num&(1<<pos) && (pos%2 == 0 || ((num&(1<<(pos-1))) == 0 )))
        r += get(num,pos+1);
    if(pos%2 == 0 || (num & (1<<(pos-1))))
        r += get(num-(num&(1<<pos)),pos+1);
    if(pos == 0)
        foi[num] = 1, fast[num] = r;
    return mp[pii(num,pos)] = r;
}


ll ans;
void bt(int pos,int num,int a=0){
    
    if(pos == w){
       int u = get(num,0);
       debug("call %d -> %d a %d\n",num,u,a);
       ans += (ll)f[a]*u;
       return;
    }
    
    if(s[0][pos])
        bt(pos+1,4*num+s[0][pos],2*a);
    if(s[1][pos])
        bt(pos+1,4*num+s[1][pos],2*a+1);

}

int main() {
    int n,q;
    scanf("%d%d%d",&w,&n,&q);
    for(int i=0;i<n;i++){
        int a, u = 0;
        scanf("%d",&a);
        f[a]++;
        for(int j=0;j<w;j++){
            int t = 2*j;
            if(a&(1<<j)) t++;
            u += (1<<t);
        }
        v[u]++;
    }
    for(int i=0;i<q;i++){
        scanf(" %s",str);
        debug("i %d\n",i);
        for(int j=0;j<w;j++){
            s[0][j] = s[1][j] = 0;
            for(int x=0;x<2;x++)
                for(int y=0;y<2;y++){
                    int r, fl = 0;
                    char t = str[j];
                    if(t >= 'a')
                        fl = 1, t = t - 'a' + 'A';
                    if(t == 'A')
                        r = (x&y);
                    if(t == 'O')
                        r = (x|y);
                    if(t == 'X')
                        r = (x^y);
                    if(fl) r ^= 1;
                    debug("%d %d %d\n",x,y,r);
                    if(r == 0) s[x][j] += (1<<y);
                }
        }
        ans = 0;
        bt(0,0);
        printf("%lld\n",ans);
        
    }
}