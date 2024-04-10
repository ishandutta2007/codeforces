#include <iostream>
#include <string>

#define A 28
#define M 1000100

#define long long long

using namespace std;

long gcd(long x, long y){
    while (x){
        y%=x;
        swap(x,y);
    }
    return y;
}

long x,y,n,m,d,n1,m1,a[A],b[A];
string s,t;

void read(void){
    cin>>x>>y;
    cin>>s>>t;
    n=s.length();
    m=t.length();
    d=gcd(n,m);
    n1=n/d;
    m1=m/d;

    long ans=0;

    for (int i=0; i<d; ++i){
        for (int j=0; j<A; ++j)
            a[j]=b[j]=0;

        for (int j=0; j+i<n; j+=d)
            a[s[i+j]-'a']++;
        for (int j=0; j+i<m; j+=d)
            b[t[i+j]-'a']++;
        for (int j=0; j<A; ++j){
            long bon=a[j]*b[j];
            bon*=(y/n1);
            ans+=bon;
        }
    }

    cout<<n*x-ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    read();
    return 0;
}