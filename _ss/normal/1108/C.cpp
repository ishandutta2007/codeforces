#include <iostream>

using namespace std;
int a[7];

int main()
{
    string s,st;
    int n,t,m;
    cin>>n>>s;
    for (int i=0;i<n;i++)
        if (i%3==0)
        {
            if (s[i]=='R')
            {
                a[1]++;
                a[2]++;
            }
            else if (s[i]=='G')
            {
                a[3]++;
                a[4]++;
            }
            else
            {
                a[5]++;
                a[6]++;
            }
        }
        else if (i%3==1)
        {
            if (s[i]=='R')
            {
                a[3]++;
                a[5]++;
            }
            else if (s[i]=='G')
            {
                a[1]++;
                a[6]++;
            }
            else
            {
                a[2]++;
                a[4]++;
            }
        }
        else
        {
            if (s[i]=='R')
            {
                a[4]++;
                a[6]++;
            }
            else if (s[i]=='G')
            {
                a[2]++;
                a[5]++;
            }
            else
            {
                a[1]++;
                a[3]++;
            }
        }
    if (a[1]>a[2])
    {
        t=1;
        m=a[1];
    }
    else
    {
        t=2;
        m=a[2];
    }
    if (a[3]>m)
    {
        t=3;
        m=a[3];
    }
    if (a[4]>m)
    {
        t=4;
        m=a[4];
    }
    if (a[5]>m)
    {
        t=5;
        m=a[5];
    }
    if (a[6]>m)
    {
        t=6;
        m=a[6];
    }
    if (t==1) st="RGB";
    if (t==2) st="RBG";
    if (t==3) st="GRB";
    if (t==4) st="GBR";
    if (t==5) st="BRG";
    if (t==6) st="BGR";
    cout<<n-m<<endl;
    for (int i=0;i<n;i++) cout<<st[i%3];
    //for (int i=1;i<=6;i++) cout<<a[i]<<" ";
    return 0;
}