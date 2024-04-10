#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    sort(s.begin(),s.end());
    vector<long long> d;
    for(int i=0;i<n-1;i++) if(s[i]!=s[i+1]) d.push_back(s[i+1]-s[i]);
    sort(d.begin(),d.end());
    long long sz=d.size();
    vector<long long> sum(n);
    if(sz) sum[0]=d[0];
    for(int i=1;i<sz;i++) sum[i]=sum[i-1]+d[i];
    int q;
    cin >> q;
    for(int o=0;o<q;o++)
    {
        long long a,b;
        cin >> a >> b;
        long long num=b-a+1;
        long long res=0;
        int l=-1,r=sz;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(d[m]<num) l=m;
            else r=m;
        }
        if(l>=0) res+=sum[l];
        res+=(sz-l)*num;
        cout << res << " ";
    }
    cout << endl;
    return 0;
}