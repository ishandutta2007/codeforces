#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
    IOS;
    int n, m;
    cin>>n>>m;
    if(min(n, m)%2)
    	cout<<"Akshat";
    else
    	cout<<"Malvika";
    return 0;
}