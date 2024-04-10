#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, ans, subt=0;
int m[4]={2, 3, 5, 7};

void recursion(int i, int prod, int ct)
{
    if(i==4)
    {
        if(ct==0)
            return;
        if(ct%2)
        {
            subt+=n/prod;
        }
        else
        {
            subt-=n/prod;
        }
        return;
    }
    recursion(i+1, prod, ct);
    recursion(i+1, prod*m[i], ct+1);
}

int32_t main()
{
    IOS;
    cin>>n;
    recursion(0, 1, 0);
    cout<<n-subt;
    return 0;
}