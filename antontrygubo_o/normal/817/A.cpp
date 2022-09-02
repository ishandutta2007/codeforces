#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define id pair<int, double>
#define ii pair<id, id>
#define di pair<double, ii>

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 9;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int x1, y1, x2, y2, x, y;
    cin>>x1>>y1>>x2>>y2>>x>>y;
    int X = fabs(x1-x2);
    int Y = fabs(y1-y2);
    if (X%x!=0||Y%y!=0) {cout<<"NO"; return 0;}
    X/=x;
    Y/=y;
    if ((X-Y)%2==0) cout<<"YES";
    else cout<<"NO";
}