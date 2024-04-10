#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

int main()
 {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n<4)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(n==4)
    {
        cout<<"1 * 2 = 2"<<endl;
        cout<<"2 * 3 = 6"<<endl;
        cout<<"6 * 4 = 24"<<endl;
        return 0;
    }
    if(n==5)
    {
        cout<<"1 + 5 = 6"<<endl;
        cout<<"3 - 2 = 1"<<endl;
        cout<<"4 * 6 = 24"<<endl;
        cout<<"24 * 1 = 24"<<endl;
return 0;
    }
    cout<<"4 * 6 = 24"<<endl;
    cout<<"5 - 3 = 2"<<endl;
    cout<<"2 - 2 = 0"<<endl;
    cout<<"0 * 1 = 0"<<endl;
    for(int i=7;i<=n;i++)
        cout<<i<<" * 0 = 0\n";
    cout<<"0 + 24 = 24"<<endl;
 }