#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> res;
        int p=1;
        while(n)
        {
            if((n%10)>0) res.push_back(p*(n%10));
            p*=10;
            n/=10;
        }
        cout << res.size() << "\n";
        for(int i=0;i<res.size();i++) cout << res[i] << " ";
        cout << "\n";
    }
    return 0;
}