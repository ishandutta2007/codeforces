#include<iostream>

using namespace std;

int main()
{
    int a[100];
    for (int i = 0; i<100; i+=12) a[i] = 31;
    for (int i = 1; i<100; i+=12) a[i] = 28;
    for (int i = 2; i<100; i+=12) a[i] = 31;
    for (int i = 3; i<100; i+=12) a[i] = 30;
    for (int i = 4; i<100; i+=12) a[i] = 31;
    for (int i = 5; i<100; i+=12) a[i] = 30;
    for (int i = 6; i<100; i+=12) a[i] = 31;
    for (int i = 7; i<100; i+=12) a[i] = 31;
    for (int i = 8; i<100; i+=12) a[i] = 30;
    for (int i = 9; i<100; i+=12) a[i] = 31;
    for (int i = 10; i<100; i+=12) a[i] = 30;
    for (int i = 11; i<100; i+=12) a[i] = 31;
    a[49] = 29;

    int n;
    cin>>n;
    int b[n];
    for (int i = 0; i<n; i++) cin>>b[i];

    int indicator = 0;
    int idx = 0;
    while ((indicator == 0)&&(idx<99-n))
    {indicator = 1;
    for (int i = 0; i<n; i++) if (a[idx+i]!=b[i]) indicator = 0;

       idx++;
    }
    if(indicator) cout<<"YES";
    else cout<<"NO";
}