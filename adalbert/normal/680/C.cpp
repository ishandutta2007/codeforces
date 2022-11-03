#include <bits/stdc++.h>;
#define fin freopen("cakes.in","r",stdin)
#define fout freopen("cakes.out","w",stdout)
using namespace std;
long long ans,n,t,t2,t3,t4,t5,mx,a[1000],k;
string s;

int main()
{
   // fin;
    //fout;
    a[1]=2;
    a[2]=3;
    a[3]=5;
    a[4]=7;
    a[5]=11;
    a[6]=13;
    a[7]=17;
    a[8]=19;
    a[9]=23;
    a[10]=29;
    a[11]=31;
    a[12]=37;
    a[13]=41;
    a[14]=43;
    a[15]=47;
    a[16]=4;
    a[17]=9;
    a[18]=25;
    a[19]=49;
    k=0;
    for (int i=1;i<=19;i++)
    {
        cout<<a[i]<<'\n';
        fflush(stdout);
        cin>>s;
        if (s=="yes") k++;
    }
    if (k>1) cout<<"composite"; else cout<<"prime";
}