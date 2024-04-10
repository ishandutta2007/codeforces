#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll cross(array<ll,2> a,array<ll,2> b){return (a[0]*b[1]-a[1]*b[0]);}
int quadrant(array<ll,2> a)
{
    auto [x,y]=a;
    if(x>0&&y>=0) return 1;
    if(x<=0&&y>0) return 2;
    if(x<0&&y<=0) return 3;
    if(x>=0&&y<0) return 4;
    return 0;
}
bool cmp(const array<ll,2> &a,const array<ll,2> &b){return (quadrant(a)<quadrant(b)||(quadrant(a)==quadrant(b)&&cross(a,b)>0));}
bool eq(array<ll,2> a,array<ll,2> b){return (quadrant(a)==quadrant(b)&&cross(a,b)==0);}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<array<ll,2>> v(n);
    for(auto &[x,y]:v) cin >> x >> y;
    sort(v.begin(),v.end(),cmp);
    int lim=(k+1)/2;
    vector<ld> branch;
    ld res=0;
    vector<ld> opt;
    int l=0;
    while(l<n)
    {
        int r=l;
        while(r+1<n&&eq(v[l],v[r+1])) r++;
        vector<ld> t;
        for(int i=l;i<=r;i++) t.push_back(hypot(ld(v[i][0]),ld(v[i][1])));
        sort(t.begin(),t.end());
        if((int)t.size()>lim) branch=t;
        for(int i=0;i<min((int)t.size(),lim);i++) opt.push_back((k-1-2*i)*t[(int)t.size()-1-i]);
        l=r+1;
    }
    sort(opt.begin(),opt.end(),greater<>());
    int cnt=k;
    for(int i=0;i<(int)opt.size()&&cnt>0;i++)
    {
        res+=opt[i];
        cnt--;
    }
    if(cnt>0)
    {
        for(int i=0;i<cnt;i++) res+=((k-1-2*(lim+i))*branch[cnt-1-i]);
    }
    cout << fixed << setprecision(8) << res << "\n";
    return 0;
}