#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> v(n);
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        sum+=v[i];
    }
    sort(v.begin(),v.end());
    int m;
    cin >> m;
    vector<int> t(m);
    for(int i=0;i<m;i++) cin >> t[i];
    for(int i=0;i<m;i++) cout << sum-v[n-t[i]] << endl;
    return 0;
}