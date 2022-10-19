#include <fstream>
#include <string>
#include <algorithm>

#define M 210
#define T 400400
#define INF 200000000

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

long a,b,n,h[M],l[T],r[T],s[M],ans=INF;

void read(void){
    cin>>n;
    cin>>a>>b;
    s[0]=0;
    for (long i=1; i<=n; ++i){
        cin>>h[i];
        s[i]=s[i-1]+h[i];
    }
    h[n+1]=0;
    s[n+1]=s[n];
}

void din(void){

    for (long j=0; j<T; ++j){
        l[j]=INF;
        r[j]=INF;
    }

    l[0]=0;

    for (long i=1; i<=n; ++i){
        for (long k=h[i]; k<=s[i]; ++k)
        r[k]=min(l[k-h[i]],(min(h[i],h[i-1])+l[s[i]-k]));
        for (long j=0; j<T; ++j){
            l[j]=r[j];
            r[j]=INF;
        }
    }

    for (long i=0; i<=a; ++i)
    if (s[n]-i<=b)
    ans=min(ans,l[i]);
    for (long i=0; i<=b; ++i)
    if (s[n]-i<=a)
    ans=min(ans,l[i]);
    ans==INF ? cout<<-1:cout<<ans;
}

int main()
{
    read();
    din();
    return 0;
}