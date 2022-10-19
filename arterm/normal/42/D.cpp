#include <iostream>
#include <set>

#define M 121

using namespace std;

int f[M];
set<int> s;

bool che(int k, int x){
    for (int i=1; i<=k; ++i)
    if (s.count(f[i]+x))
    return 0;
    return 1;
}

void add(int k, int x){
    f[k+1]=x;
    for (int i=1; i<=k; ++i)
    s.insert(f[i]+x);
}

int main()
{
    int n;
    cin>>n;

    f[1]=1;
    int k=1;
    for (int i=2; k<=n; ++i)
    if (che(k,i)){
        add(k,i);
        k++;
    }

    for (int i=1; i<=n; ++i,cout<<"\n")
    for (int j=1; j<=n; ++j,cout<<" ")
    if (i==j)
    cout<<0;
    else
    cout<<f[i]+f[j];
    return 0;
}