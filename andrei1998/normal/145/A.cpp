#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int inv[10];
int main()
{
    string a,b;
    cin>>a>>b;

    int n=a.size();
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            inv[a[i]-'0']++;

    cout<<min(inv[4],inv[7])+abs(inv[4]-inv[7])<<'\n';
    return 0;
}