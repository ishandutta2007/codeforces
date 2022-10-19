#include <fstream>
#include <string>
#include <algorithm>

#define M 200

using namespace std;

ifstream cin ("input.txt");
ofstream cout("output.txt");

string s;
long m,k,n,c=0,lm=0,rm=0,a[M],b[M],f[M];
long l[M],r[M];
bool fl;

void read(void){
    cin>>m>>k;
    for (long i=0; i<k; ++i)
    cin>>a[i];
    cin>>n;

    for (long i=0,h,t; i<n; ++i){
        cin>>s>>h;

        l[i]=r[i]=f[i]=0;

        for (long j=0; j<h; ++j){
            cin>>t;
            if (t>0)
            for (long g=0; g<k; ++g)
            if (a[g]==t){
                l[i]++;
                r[i]++;
                f[i]++;
                break;
            }

            if (t==0)
            f[i]++;
        }
        f[i]=min(k,f[i]);
        r[i]=f[i];
        if (h>m-k)
        l[i]=max(l[i],(h-m+k));
        lm=max(lm,l[i]);
        rm=max(rm,r[i]);

    }
    for (long i=0; i<n; ++i){
        if (r[i]<lm)
        b[i]=1;

        if (r[i]>=lm)
        b[i]=2;

        if (l[i]==rm)
        b[i]=0;

        //cout<<b[i]<<"\n";
    }
    for (long i=0; i<n; ++i){
        fl=1;


        if (b[i]==2)
        for (long j=0; j<n; ++j)
        if (i!=j && l[i]<r[j])
        fl=0;

        if (b[i]==2 && fl)
        b[i]=0;
    }


    for (long i=0; i<n; ++i)
    cout<<b[i]<<"\n";
}

int main()
{
    read();
    return 0;
}