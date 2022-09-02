#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int l = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    

    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) l+=a[i];
    int maxx = 0;
    for (int s = 0; s<k; s++)
    {
        int l1 = l;
        for (int i = s; i<n; i+=k) l1-=a[i];
        maxx = max(maxx, abs(l1));
    }
    cout<<maxx;
}