#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int res=0;
    for(int o=0;o<n-1;o++)
    {
        for(int i=o+1;i<n;i++)
        {
            int p=a[o]+a[i];
            int cnt=1;
            int l=o+1,r=i-1;
            while(l<r)
            {
                if(a[l]+a[r]==p)
                {
                    cnt++;
                    l++;
                    r--;
                }
                else if(a[l]+a[r]<p) l++;
                else if(a[l]+a[r]>p) r--;
            }
            res=max(res,cnt);
        }
    }
    cout << res << endl;
    return 0;
}