#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gibon cin.tie(0); ios::sync_with_stdio(false);

int main()
{
    gibon
    int N;
    cin >> N;
    double a=0;
    for(int i=1;i<=N;i++)
    {
        a+=(double)1/i;
    }
    cout << a;
}