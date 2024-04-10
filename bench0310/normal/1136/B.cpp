#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1,1);
    if(n-k+1<k) k=n-k+1;
    int res=0;
    int idx=k;
    while(idx>1)
    {
        v[idx]--;
        v[idx+1]++;
        res+=2;
        idx--;
    }
    res+=3;
    v[1]--;
    v[2]++;
    idx++;
    while(idx<n)
    {
        res+=v[idx];
        if(idx>k) res++;
        res++;
        idx++;
    }
    res+=v[n];
    res++;
    cout << res << endl;
    return 0;
}