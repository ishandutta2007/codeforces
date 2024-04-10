#include <bits/stdc++.h>

using namespace std;

#define fir first
#define sec second
#define pb push_back
#define int ll

typedef long long ll;

int a[100000];

signed main()
{
    string st1,st2;
    cin>>st1>>st2;

    int now1=int(st1.size())-1;
    int now2=int(st2.size())-1;

    while (now1>=0 && now2>=0 && st1[now1]==st2[now2])
    {
        now1--;
        now2--;
    }

    cout<<now1+1+now2+1;
}