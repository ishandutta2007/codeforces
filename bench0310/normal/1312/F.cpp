#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<array<int,3>> grundy[6][6][6];
    const int lim=50;
    int period[6][6][6];
    for(int x=1;x<=5;x++)
    {
        for(int y=1;y<=5;y++)
        {
            for(int z=1;z<=5;z++)
            {
                const int N=10000;
                vector<array<int,3>> &g=grundy[x][y][z];
                g.assign(N+1,{0,0,0});
                auto gg=[&](int sz,int st,int nxt)->int
                {
                    if(st!=0&&st==nxt) return 4;
                    int c=(nxt==0?x:(nxt==1?y:z));
                    return g[max(0,sz-c)][nxt];
                };
                for(int i=1;i<=N;i++)
                {
                    for(int j=0;j<=2;j++)
                    {
                        vector<bool> to(5,0);
                        for(int k=0;k<=2;k++) to[gg(i,j,k)]=1;
                        for(int k=3;k>=0;k--) if(to[k]==0) g[i][j]=k;
                    }
                }
                //sequence must be periodic in [lim,N]
                array<int,3> tmp={0,0,0};
                for(int i=0;i<=2;i++)
                {
                    int pnow=0;
                    for(int p=1;p<=N;p++)
                    {
                        bool ok=1;
                        for(int j=lim;j+p<=N;j++) ok&=(g[j][i]==g[j+p][i]);
                        if(ok)
                        {
                            pnow=p;
                            break;
                        }
                    }
                    assert(pnow!=0);
                    assert(pnow<=10);
                    tmp[i]=pnow;
                }
                assert(tmp[0]==tmp[1]&&tmp[1]==tmp[2]);
                period[x][y][z]=tmp[0];
            }
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n,x,y,z;
        cin >> n >> x >> y >> z;
        vector<ll> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        auto g=[&](ll sz,int st)->int
        {
            if(sz<lim) return grundy[x][y][z][sz][st];
            int p=period[x][y][z];
            return grundy[x][y][z][lim+sz%p+p-lim%p][st];
        };
        ll sum=0;
        for(int i=1;i<=n;i++) sum^=g(a[i],0);
        int res=0;
        array<int,3> mv={x,y,z};
        if(sum!=0)
        {
            for(int i=1;i<=n;i++)
            {
                for(int nxt=0;nxt<=2;nxt++)
                {
                    res+=((sum^g(a[i],0)^g(max(0ll,a[i]-mv[nxt]),nxt))==0);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}