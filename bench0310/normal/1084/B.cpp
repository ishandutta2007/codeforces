#include <iostream>

using namespace std;

int main()
{
    long long n,s;
    cin >> n >> s;
    long long sum=0;
    long long v[n];
    long long m=1000000000000;
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        sum+=v[i];
        m=min(m,v[i]);
    }
    if(s>sum) cout << -1 << endl;
    else cout << min((sum-s)/n,m) << endl;
    return 0;
}