#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
#define NMAX 2005
using namespace std;

int n;
class disjoint_set{
public:
int tata[NMAX];
    int h[NMAX];
    int marime[NMAX];
    int ind;
    int cate;

    int f(int x){
        if(x!=tata[x])
            tata[x]=f(tata[x]);
        return tata[x];
    }

    inline void unite(int a,int b){
        a=f(a),b=f(b);

        if(a==b)
            return;
        cate --;

        if(h[a]>h[b]){
            tata[b]=a;
            marime[a]+=marime[b];
        }
        else{
            if(h[a]==h[b])
                h[b]++;

            tata[a]=b;
            marime[b]+=marime[a];
        }
    }
    inline void init(){
        for(int i=1;i<=n;i++){
            tata[i]=i;
            h[i]=marime[i]=1;
        }
        cate = n;
    }
};

disjoint_set S;

int main()
{
    int m, k;
    cin >> n >> m >> k;

    S.init();

    int j;
    int start = 1;
    int ed = n;

    for (int i = k; i > 0; i -= 2, start ++, ed --) {
        for (j = start; j + i - 1 <= ed; j++)
            S.unite(j, j + i - 1);
    }

    int ans = 1;
    for (int i = 0; i < S.cate; i++)
        ans = (1ll * ans * m) % mod;

    cout << ans<< endl;
    return 0;
}