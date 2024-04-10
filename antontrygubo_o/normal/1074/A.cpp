#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

int n, m;

vector<int> ver;
vector<int> hor;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    

    cin>>n>>m;
    int x1, x2, y;
    int counter = 0;
    for (int i = 0; i<n; i++) {cin>>x1; ver.push_back(x1);}
    for (int i = 0; i<m; i++) {cin>>x1>>x2>>y; if (x1==1&&x2==1000000000) counter++; else if (x1==1) hor.push_back(x2);}
    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end());
    
    /*print(ver);
    print(hor);*/
    
    int h = hor.size();
    
    int minn = 1000000;
    for (int i = 0; i<n; i++)
    {
        int it = lower_bound(hor.begin(), hor.end(), ver[i]) - hor.begin();
        minn = min(minn, i + h-it);
    }
    minn = min(minn, n);
    cout<<minn+counter;
    
}