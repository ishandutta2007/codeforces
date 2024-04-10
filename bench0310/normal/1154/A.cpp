#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v(4);
    for(int i=0;i<4;i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    for(int i=1;i<4;i++) cout << v[0]-v[i] << " ";
    cout << endl;
    return 0;
}