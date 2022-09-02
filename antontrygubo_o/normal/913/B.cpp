#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> parent(n);
    int t;
    for (int i = 0; i<n-1; i++) {cin>>parent[i+1]; parent[i+1]--;}
    vector<int> counter(n);
    for (int i = 1; i<n; i++) counter[parent[i]]++;
    vector<int> good(n);
    for (int i = 0; i<n; i++) if (counter[i]==0) good[parent[i]]++;
    for (int i = 0; i<n; i++)
    {
        if (counter[i]!=0&&good[i]<3) {cout<<"No"; return 0;}
    }
    cout<<"Yes";

}