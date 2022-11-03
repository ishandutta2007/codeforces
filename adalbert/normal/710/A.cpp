#include <bits/stdc++.h>
using namespace std;
#define ll  long long
string st;
ll ans;
///---program start---///
int main()
{
    cin>>st;
    if (st[0]-1>='a') ans++;
    if (st[0]+1<='h') ans++;
    if (st[1]-1>='1') ans++;
    if (st[1]+1<='8') ans++;
    if (st[0]-1>='a' && st[1]-1>='1') ans++;
    if (st[0]-1>='a' && st[1]+1<='8') ans++;
    if (st[0]+1<='h' && st[1]-1>='1') ans++;
    if (st[0]+1<='h' && st[1]+1<='8') ans++;
    cout<<ans;
}