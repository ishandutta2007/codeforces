#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        k-=2;
        auto peak=[&](int i)->int{return (1<i&&i<n&&a[i-1]<a[i]&&a[i]>a[i+1]);};
        int cnt=0;
        for(int i=2;i<=k;i++) cnt+=peak(i);
        int res=-1;
        int l=0;
        for(int i=k+1;i<=n-1;i++)
        {
            cnt+=peak(i);
            if(cnt>res)
            {
                res=cnt;
                l=i;
            }
            cnt-=peak(i-k+1);
        }
        cout << res+1 << " " << l-k << "\n";
    }
    return 0;
}