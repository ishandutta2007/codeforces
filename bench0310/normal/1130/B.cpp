#include <bits/stdc++.h>

using namespace std;

long long ab(long long a)
{
    if(a>=0) return a;
    else return -a;
}

int main()
{
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    vector<long long> v[n+1];
    long long temp;
    for(long long i=0;i<2*n;i++)
    {
        cin >> temp;
        v[temp].push_back(i);
    }
    long long res=0;
    long long a=0,b=0;
    for(long long i=1;i<=n;i++)
    {
        res+=min(ab(a-v[i][0])+ab(b-v[i][1]),ab(a-v[i][1])+ab(b-v[i][0]));
        a=v[i][0];
        b=v[i][1];
    }
    cout << res << endl;
    return 0;
}