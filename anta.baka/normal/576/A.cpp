#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> prime(n+1, 1);
    for(int i=2; i*i<=n; i++)
        if(prime[i])
            for(int j=i*i; j<=n; j+=i)
                prime[j] = 0;
    vector<int> ans;
    for(int i=2; i<=n; i++)
        if(prime[i])
            for(int j=i; j<=n; j*=i)
                ans.push_back(j);
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}