#include <iostream>
#include <vector>

#define M 100100

using namespace std;

vector<long> a[M],o[M],l(M,0),t(M,0);
long A=0,O=0,n,m,p=0;
bool u[M];
char ch;

int main()
{
    long h;
    cin>>n>>m;
    for (long i=1; i<=n; ++i){
        cin>>ch>>h;
        ch=='+' ? a[h].push_back(i) : o[h].push_back(i);
        ch=='+' ? A++ : O++;
        ch=='+' ? u[i]=1:u[i]=0;
    }

    m-=O;

    for (long i=1; i<=n; ++i)
    if (a[i].size()-o[i].size()==m){
        p++;
        for (long j=0; j<a[i].size(); ++j)
        l[a[i][j]]--;
        for (long j=0; j<o[i].size(); ++j)
        l[o[i][j]]++;
    }

    for (long i=1; i<=n; ++i)
    if (!u[i])
    l[i]-=p;


    for (long i=1; i<=n; ++i){
        if (l[i]+p==0)
        cout<<"Truth\n";
        if (l[i]==0)
        cout<<"Lie\n";
        if (0<l[i]+p && l[i]<0)
        cout<<"Not defined\n";
    }

    return 0;
}