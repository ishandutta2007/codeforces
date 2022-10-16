#include <iostream>
#include <algorithm>

using namespace std;

int k;
int v[2000005];

inline int sum(int a,int b){
    return (v[b]-v[a-1]);
}

inline bool ok(int nr){
    for(int i=nr;i<=1000000;i+=nr)
        if(sum(min(i+k+1,i+nr),i+nr-1))
            return 0;
    return 1;
}

int main()
{
    int n=0;
    cin>>n>>k;

    int x=0;

    int minim=1000005;
    while(n--){
        cin>>x;
        v[x]++;

        minim=min(minim,x);
    }

    for(int i=1;i<=2000000;i++)
        v[i]+=v[i-1];

    for(int i=minim;i>=2;i--)
        if(ok(i)){
            cout<<i<<'\n';
            return 0;
        }

    cout<<"1\n";
    return 0;
}