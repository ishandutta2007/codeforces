#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n, m;
    cin>>n>>m;
    if (n>m+1) {cout<<"Impossible"; return 0;}
    vector<pair<int, int>> edges;
    int counter = 0;
    for (int i =2; i<=n; i++) edges.push_back(make_pair(1, i));
    counter = n-1;
    for (int i = 3; i<=n; i++)
    {
        if (counter<m)
        {
            int j = 2;
            while (j!=i&&counter<m)
            {
                if (__gcd(i, j)==1) {counter++; edges.push_back(make_pair(i, j));}
                j++;
            }
        }
    }
    if (counter<m) cout<<"Impossible";
    else
    {
        cout<<"Possible"<<endl;
        for (int i = 0; i<edges.size(); i++) cout<<edges[i].first<<' '<<edges[i].second<<endl;
    }
}