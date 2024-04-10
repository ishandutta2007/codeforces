#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v={0,5,3,2,4,1};
    int x;
    cin >> x;
    int res=0;
    for(int i=0;i<6;i++) if(x&(1<<(6-i-1))) res+=(1<<(6-v[i]-1));
    cout << res << endl;
    return 0;
}