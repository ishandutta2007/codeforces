#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ET cout << "\n"
#define FILL(i,n) memset(i,n,sizeof i)
#define SZ(a) ((int)a.size())
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

struct mode
{
    int x,y,z,i;
    bool operator<(const mode &a)const{
        if(x==a.x&&y==a.y) return z<a.z;
        if(x==a.x) return y<a.y;
        return x<a.x;
    } 
}arr[50005];

int main()
{
    IOS();
    int n,ls=-1;
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> arr[i].x >> arr[i].y >> arr[i].z,arr[i].i=i+1;
    sort(arr,arr+n);
    for(int i=0,j=0,k=0;i<n;i=j)
    {
        int lss=-1;
        while(j<n&&arr[i].x==arr[j].x)
        {
            vector<int> v;
            for(k=j;k<n&&arr[j].x==arr[k].x&&arr[j].y==arr[k].y;)
                v.pb(arr[k].i),++k;
            for(int i=0;i+1<SZ(v);i+=2)
                cout << v[i] << " " << v[i+1] << "\n";
            if(SZ(v)&1)
                if(~lss) cout << lss << " " << v.back() << "\n",lss=-1;
                else lss=v.back();
            j=k;
        }
        if(~lss)
            if(~ls) cout << ls << " " << lss << "\n",ls=-1;
            else ls=lss;
    }
}