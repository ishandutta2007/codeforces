#include <bits/stdc++.h>

using namespace std;

int query(string t)
{
    cout << t << "\n";
    cout.flush();
    int e;
    cin >> e;
    if(e==0) exit(0);
    return e;
}

string as(int n)
{
    string t;
    for(int i=0;i<n;i++) t+="a";
    return t;
}

int main()
{
    int val=query(as(300))-300;
    int n=query(as(1))+1-max(val+1,0);
    int b=val+n;
    string res=as(n);
    int e=b;
    for(int i=0;i<n-1;i++)
    {
        res[i]='b';
        if(query(res)<e) e--;
        else res[i]='a';
    }
    if(e==1) res[n-1]='b';
    query(res);
    return 0;
}