#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int query(int y)
{
    cout << y << "\n";
    cout.flush();
    int a;
    cin >> a;
    if(a==0) exit(0);
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    vector<bool> v(n);
    for(int i=0;i<n;i++) v[i]=(query(1)==1);
    int l=1,r=m+1;
    int idx=0;
    while(l<r-1)
    {
        int mid=(l+r)/2;
        if((query(mid)*(v[idx]==0?-1:1))==1) l=mid;
        else r=mid;
        idx=(idx+1)%n;
    }
    return 0;
}