#include <iostream>

using namespace std;

long long int pw (int a, int b) {
    long long int ans=1;
    for(int i=1;i<=b;i++)
        ans*=a;

    return ans;
}

int n;
int ans[55];

void build(long long int k, int st, int dr, int poz) {
    if(poz==(n+1))
        return;

    if(k<=pw(2,dr-st-1))
        ans[st++]=poz++;
    else {
        k-=pw(2,dr-st-1);
        ans[dr--]=poz++;
    }

    build(k,st,dr,poz);
}

int main()
{
    cin>>n;

    long long int k=0;
    cin>>k;

    build(k,1,n,1);

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}