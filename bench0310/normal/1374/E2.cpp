#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<array<int,4>> v(n);
    for(auto &[t,a,b,id]:v) cin >> t >> a >> b;
    for(int i=0;i<n;i++) v[i][3]=i+1;
    sort(v.begin(),v.end());
    vector<array<int,2>> both={{0,0}};
    vector<array<int,2>> alice={{0,0}};
    vector<array<int,2>> bob={{0,0}};
    vector<array<int,4>> nand={{0,0,0,0}};
    for(auto [t,a,b,id]:v)
    {
        if(a==1&&b==1) both.push_back({both.back()[0]+t,id});
        else
        {
            if(a==1) alice.push_back({alice.back()[0]+t,id});
            if(b==1) bob.push_back({bob.back()[0]+t,id});
            auto [ts,ta,tb,tid]=nand.back();
            nand.push_back({ts+t,ta+a,tb+b,id});
        }
    }
    int both_sz=(int)both.size()-1;
    int alice_sz=(int)alice.size()-1;
    int bob_sz=(int)bob.size()-1;
    int nand_sz=(int)nand.size()-1;
    const int inf=numeric_limits<int>::max();
    array<int,3> opt={inf,-1};
    for(int i=min(m,both_sz);i>=0;i--)
    {
        if(alice_sz<k-i||bob_sz<k-i||m-i<2*k-2*i||nand_sz<m-i) break;
        int need=max(0,k-i);
        int cnt=m-i-2*need;
        auto e=[&](int l)->array<int,2>
        {
            auto [t,a,b,id]=nand[l];
            int c=l-a-b+max(0,a-need)+max(0,b-need);
            int s=t-alice[min(need,a)][0]-bob[min(need,b)][0];
            return {c,s};
        };
        int l=-1,r=nand_sz;
        while(l<r-1)
        {
            int mid=(l+r)/2;
            if(e(mid)[0]>=cnt) r=mid;
            else l=mid;
        }
        opt=min(opt,{both[i][0]+alice[need][0]+bob[need][0]+e(r)[1],i,r});
    }
    if(opt[0]!=inf)
    {
        auto [res,i,l]=opt;
        cout << res << "\n";
        int need=max(0,k-i);
        for(int j=1;j<=i;j++) cout << both[j][1] << " ";
        for(int j=1;j<=need;j++) cout << alice[j][1] << " " << bob[j][1] << " ";
        for(int j=1;j<=l;j++) if(!(nand[j][1]-nand[j-1][1]==1&&nand[j][1]<=need)&&!(nand[j][2]-nand[j-1][2]==1&&nand[j][2]<=need)) cout << nand[j][3] << " ";
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}