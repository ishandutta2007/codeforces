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

const ll p = 1e9 + 7;
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int n;
    cin>>n;
    char x = 'a';
    string s = "z";
    while (n)
    {
        int i = 0;
        while ((i*(i+1))/2<=n) i++;
        n-=(i*(i-1))/2;
        for (int j = 0; j<i; j++) s+=x;
        x++;
    }
    cout<<s;
}