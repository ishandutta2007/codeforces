#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    cout << v[n-1] << " ";
    n=v[n-1];
    for(int i=1;i*i<=n;i++)
    {
        if(n%i) continue;
        int a=i;
        for(int j=0;j<(int)v.size();j++)
        {
            if(v[j]==a)
            {
                v.erase(v.begin()+j);
                break;
            }
        }
        if(i*i==n) continue;
        a=n/i;
        for(int j=0;j<(int)v.size();j++)
        {
            if(v[j]==a)
            {
                v.erase(v.begin()+j);
                break;
            }
        }
    }
    cout << v[v.size()-1] << endl;
    return 0;
}