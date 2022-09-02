#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> x;
vector<long long> y;

bool check3(int i, int j, int k)
{
    if ( (x[i]-x[j])*(y[i]-y[k])==(y[i]-y[j])*(x[i]-x[k])) return true;
    else return false;
}

bool checklinegood(int i, int j)
{
    vector<int> notvisited;
    for (int s = 0; s<n; s++) if (!check3(i, j, s)) notvisited.push_back(s);
    if (notvisited.size()<=2) return true;
    
    int len = notvisited.size();
    for (int g = 2; g<len; g++) if (!check3(notvisited[0], notvisited[1], notvisited[g])) return false;
    return true;
}

int main() 
{
cin>>n;
if (n<=4) {cout<<"YES"; return 0;}
for (int i = 0; i<n; i++) 
{
    long long a, b;
    cin>>a>>b;
    x.push_back(a);
    y.push_back(b);
}

if (checklinegood(0, 1)) {cout<<"YES"; return 0;}
if (checklinegood(0, 2)) {cout<<"YES"; return 0;}
if (checklinegood(2, 1)) {cout<<"YES"; return 0;}
cout<<"NO";


}